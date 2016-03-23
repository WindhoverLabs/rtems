/*
 *  COPYRIGHT (c) 1989-2009.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <tmacros.h>

#include <sys/types.h>
#include <rtems/score/threadqimpl.h>

const char rtems_test_name[] = "SPTHREADQ 1";

static Thread_queue_Control queue = THREAD_QUEUE_INITIALIZER( "Queue" );

static rtems_task Init(
  rtems_task_argument ignored
)
{
  TEST_BEGIN();

  puts( "Init - _Thread_queue_Extract - thread not blocked on a thread queue" );
  _Thread_Disable_dispatch();
  _Thread_queue_Extract( _Thread_Executing );
  _Thread_Enable_dispatch();
  /* is there more to check? */

  rtems_test_assert( queue.Queue.heads == NULL );

  TEST_END();
  rtems_test_exit(0);
}

/* configuration information */

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_DOES_NOT_NEED_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_TASKS  1
#define CONFIGURE_INITIAL_EXTENSIONS RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT
#include <rtems/confdefs.h>

/* global variables */
