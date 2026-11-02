/*
 * PROJECT:     ReactOS CRT library
 * LICENSE:     BSD - See COPYING.ARM in the top level directory
 * PURPOSE:     Implementation of _chkstk and _alloca_probe
 * COPYRIGHT:   Copyright 2014 Timo Kreuzer (timo.kreuzer@reactos.org)
 *              Copyright 2014 Yuntian Zhang (yuntian.zh@gmail.com)
 *              Copyright 2019 Mohamed Mediouni (mmediouni@gmx.fr)
 */

/* INCLUDES ******************************************************************/

/* CODE **********************************************************************/
    AREA |.text|, CODE, READONLY, ALIGN=2

    EXPORT __chkstk
__chkstk
    ; TODO: implement proper stack probing
    ret

    EXPORT __alloca_probe
__alloca_probe
    ; TODO: add an assert fail call, as this is unimplemented
    ret

    END
/* EOF */
