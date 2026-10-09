# unit_0219BA58 (ov009)

Round 5 (lane s06): the 14 parts were rebuilt by hand on one canonical type block
(src/game/ov009/qr2_types.h) and merged into three EXACT parts.

Parts:

- unit_0219BA58_p01.c: 0x0219BA54..0x0219C3A4 (NatNegProgressCallback, which was
  its own file unit_0219BA54.c, through qr_process_query)
- unit_0219BA58_p02.c: func_0219C3A4 (qr_process_client_message)
- unit_0219BA58_p03.c: 0x0219C554..end (qr_got_recent_message through send_heartbeat)

Why p02 stays separate: the function holds a six-byte compiler template (natNegBytes).
tools/match.py resolves that relocation (@13818 row) only when the compare starts at
the function's own SDK row. In a merged file the compare starts at an earlier row and
the one relocation stays unresolved, which turns the verdict into DIFF. The code itself
merges byte-exact (checked with all 17 functions in one file).

func_0219BA54, func_0219BA58, func_0219BA84 and func_0219BE80 are file-local (static) in
the vendor object but are plain external here because p02 and p03 call them.
