@c
@c  RTEMS Remote Debugger Server Specifications
@c
@c  Written by: Eric Valette <valette@crf.canon.fr>
@c              Emmanuel Raguet <raguet@crf.canon.fr>
@c
@c
@c  $Id$
@c

@chapter Conclusion

In this document we have presented how we envisage to add remote debugging facilities
to RTEMS by implementing a remote debugger daemon for GDB. As any debug implemented
in software, it will have limitation but we are confident that most of them
can be removed by adding separate software components dedicated to debug activity.
We must keep in mind that even with this approach, no software will enable the
debug of code with interrupt entirely masked at processor level and that In
Circuit Emulator (ICE) or use of BDM extension on the target board are the ultimate
way to really debug any portion of an RTOS. BDM support in GDB is still weak
but people are working on it and we may get something better in a near future.

@example
XXXXX insert process.eps
XXXXX Caption remote debugger tasks and handlers
@end example

