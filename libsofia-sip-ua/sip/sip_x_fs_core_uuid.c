/*
 * This file is part of the Sofia-SIP package
 *
 * Copyright (C) 2005 Nokia Corporation.
 *
 * Contact: Pekka Pessi <pekka.pessi@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

/**@CFILE sip_x_fs_core_uuid.c
 * @brief Non-critical SIP headers
 *
 * This file contains implementation of @X-FS-Core-UUID header.
 *
 * @author Pekka Pessi <Pekka.Pessi@nokia.com>.
 *
 * @date Created: Tue Jun 13 02:57:51 2000 ppessi
 */

#include "config.h"

/* Avoid casting sip_t to msg_pub_t and sip_header_t to msg_header_t */
#define MSG_PUB_T       struct sip_s
#define MSG_HDR_T       union sip_header_u


#include "sofia-sip/sip_parser.h"
#include "sofia-sip/sip_extra.h"
#include "../su/sofia-sip/su_alloc.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#
#include <assert.h>

/* ====================================================================== */

/**@SIP_HEADER sip_x_fs_core_uuid X-FS-Core-UUID Header
 *
 * The X-FS-Core-UUID header contains information about the client uuid.
 * Its syntax is defined in [H14.43, S10.45] as
 * follows:
 *
 * @code
 *    X-FS-Core-UUID   =  "X-FS-Core-UUID" HCOLON uuid *(LWS uuid)
 *    uuid             =  token
 * @endcode
 *
 * The parsed X-FS-Core-UUID header is stored in #sip_x_fs_core_uuid_t structure.
 */

/**@ingroup sip_x_fs_core_uuid
 * @typedef struct msg_generic_s sip_x_fs_core_uuid_t;
 *
 * The structure #sip_x_fs_core_uuid_t contains representation of a SIP
 * @X-FS-Core-UUID header.
 *
 * The #sip_x_fs_core_uuid_t is defined as follows:
 * @code
 * typedef struct msg_generic_s
 * {
 *   msg_common_t   g_common[1];    // Common fragment info
 *   msg_generic_t *g_next;	    // Link to next header
 *   char const    *g_string;	    // User-Agent components
 * } sip_x_fs_core_uuid_t;
 * @endcode
 */

msg_hclass_t sip_x_fs_core_uuid_class[] =
SIP_HEADER_CLASS_G(x_fs_core_uuid, "X-FS-Core-UUID", "", single);

issize_t sip_x_fs_core_uuid_d(su_home_t *home, sip_header_t *h, char *s, isize_t slen)
{
  return sip_generic_d(home, h, s, slen);
}

issize_t sip_x_fs_core_uuid_e(char b[], isize_t bsiz, sip_header_t const *h, int f)
{
  assert(sip_x_fs_core_uuid_p(h));
  return sip_generic_e(b, bsiz, h, f);
}
