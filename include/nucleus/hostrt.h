#ifndef _XENO_NUCLEUS_HOSTRT_H
#define _XENO_NUCLEUS_HOSTRT_H

/*!\file hostrt.h
 * \brief Definitions for global semaphore heap shared objects
 * \author Wolfgang Mauerer
 *
 * Copyright (C) 2010 Wolfgang Mauerer <wolfgang.mauerer@siemens.com>.
 *
 * Xenomai is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * Xenomai is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Xenomai; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include <nucleus/types.h>
#ifdef __KERNEL__
#include <asm-generic/xenomai/system.h>
#else /* !__KERNEL__ */
#include <time.h>
#include <sys/types.h>
#include <nucleus/seqlock_user.h>
typedef u_int32_t u32;
typedef u_int64_t cycle_t;

/*
 * xnarch_hostrt_data must be kept in sync with the corresponding ipipe
 * definitions in ipipe_tickdev.h We cannot directly include the file
 * here because the definitions are also required in Xenomai userland.
 */
struct xnarch_hostrt_data {
	short live;
	seqcount_t seqcount;
	time_t wall_time_sec;
	u32 wall_time_nsec;
	struct timespec wall_to_monotonic;
	cycle_t cycle_last;
	cycle_t mask;
	u32 mult;
	u32 shift;
};
#endif /* !__KERNEL__ */

#endif