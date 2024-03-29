#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "../spfatal_support/spfatal.h"

/*
 * Classic API Init task create failure
 *
 *  COPYRIGHT (c) 1989-2008.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#include <rtems/score/wkspace.h>

#define FATAL_ERROR_TEST_NAME            "8"
#define FATAL_ERROR_DESCRIPTION          "Core workspace too small"
#define FATAL_ERROR_EXPECTED_SOURCE      INTERNAL_ERROR_CORE
#define FATAL_ERROR_EXPECTED_ERROR       INTERNAL_ERROR_WORKSPACE_ALLOCATION

static void force_error(void)
{
  _Workspace_Allocate_or_fatal_error( SIZE_MAX );
  /* we will not run this far */
}

#include "../spfatal_support/spfatalimpl.h"
