/*
 * func_0204960C -- seek an open archive stream to an absolute position.
 * REIMPLEMENTATION, not a match.
 *
 * Two matched call sites pin the semantics, and they agree:
 *
 *   src/matched/sub_02045EC0.c (EXACT), the message-bank loader:
 *       sub_0204960C(bank->stream, pos + (index * 8 + 4));
 *       sub_020495F4(bank->stream, 8, &bank->cache);
 *     - an absolute byte position computed by the caller, then an 8-byte
 *       read of the entry descriptor that lives there.
 *
 *   src/matched/unit_0201ADA4.c (EXACT), the personal-record loader:
 *       func_0204960C(handle, func_02049578(handle, member));
 *       func_020495F4(handle, 0x3C, dest);
 *     - and src/matched/func_02049578.c (EXACT) returns exactly
 *       `arc->imageBase + 8 + start`, an absolute position in the archive
 *       file.
 *
 * src/matched/func_020495F4.c is a one-line forward to FS_ReadFile, which
 * reads from the stream's current position.  So this function is the seek
 * half of the same pair: FS_SeekFile(file, pos, FS_SEEK_SET).  That is the
 * only reading under which either call site works.
 *
 * Not claimed byte-matching, and not claimed to reproduce whatever range
 * check or seek-mode argument the original carries.  When 0x0204960C is
 * decompiled, delete this file and put the matched source in
 * port/CMakeLists.txt instead.
 *
 * (layout/symbols_sdk.txt names 0x0204960C NHTTPi_GetConnection with the `?`
 * weak-evidence flag; a `?` row is explicitly not trustworthy and this is a
 * game function.)
 */

#include "stubs.h"

extern s32 FS_SeekFile(void *file, s32 offset, u32 origin);

void func_0204960C(void *file, u32 pos)
{
    if (!FS_SeekFile(file, (s32)pos, 0)) {
        bw_panic("archive seek", 0x0204960C, "seek past end of archive");
    }
}
