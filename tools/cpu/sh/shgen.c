/*
 * Copyright (c) 1998-1999 Ralf Corsepius (corsepiu@faw.uni-ulm.de)
 *
 * See the file COPYING for copyright notice.
 */

#include <stdio.h>
#include <string.h>	/* strcmp, strerror */
#include <errno.h>
#include <getopt.h>

#include "sci.h"

static void usage( char *prog )
{
  fprintf( stderr, "usage: %s [options] driver\n", prog );
  fprintf( stderr, "options:\n" );
  fprintf( stderr, "\t-M Phi      .. processor frequency [MHz]\n" );
  fprintf( stderr, "\t-K Phi      .. processor frequency [KHz]\n" );
  fprintf( stderr, "\t-H Phi      .. processor frequency [Hz]\n" );
  fprintf( stderr, "\t\t..default 20MHz" );
  fprintf( stderr, "driver:\n" );
  fprintf( stderr, "\tsci .. bitrate table for sci\n" );
  exit ( 1 );
}

static void shgen_header( FILE *file )
{
  fprintf( file, 
    "/*\n * DO NOT EDIT - this file is automatically generated by shgen 0.3\n" );
  fprintf( file,
    " * Copyright (c) 1998-1999, Ralf Corsepius (corsepiu@faw.uni-ulm.de)\n */\n" );
  fprintf( file, 
    "\n/* This file is not copyrighted */\n\n" );
}

int main( int argc, char *argv[] )
{
  double 	Phi = 20.0 ;
  
  while ( ( optopt = getopt( argc, argv, "M:K:H:" ) ) > 0 )
  {
    switch ( optopt )
    {
    case 'M' :
      sscanf( optarg, "%lf", &Phi ); 
      Phi = Phi * 1000000.0;
      break ;
    case 'K' :
      sscanf( optarg, "%lf", &Phi ); 
      Phi = Phi * 1000.0;
      break ;
    case 'H' :
      sscanf( optarg, "%lf", &Phi ); 
      break ;
    default  :
      usage( argv[0] );
      break ;
    }
  }

  if ( argc - optind != 1 )
    usage( argv[0] );

  shgen_header( stdout );
      
  if ( strcmp( argv[optind], "sci" ) == 0 )
  {
    shgen_gensci( stdout, Phi );
  }
  else
    usage( argv[0] );
      
  return 0 ;
}
