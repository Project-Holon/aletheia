/*
 * func_02048DDC -- open an archive handle by archive id.  NOT MATCHED.
 *
 * The id-to-NitroFS-path table it consults lives in ARM9 data that no
 * matched file reads yet, so the port cannot honour the call.  Anything in
 * the port that needs an archive opens it by path through bw_arc_open
 * instead; reaching this stub means a matched TU took the id path and the
 * closure is wrong about it.
 */
#include "stubs.h"

BW_STUB(func_02048DDC, 0x02048DDC, "archive open by id: id table not decompiled")
