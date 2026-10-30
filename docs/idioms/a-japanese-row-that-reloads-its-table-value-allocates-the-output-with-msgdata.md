# A Japanese row that reloads its table value allocates the output with MSGDATA

summary: in the Japanese cartridge a number row reloads `table[i].value` after the count call
and calls MSGDATA_AllocString twice; the second call replaces `STRBUF_Create(0x80, heap)`. With
that one change the register allocation of the whole loop matches.

Residue: Japanese row setup loops have the right length but a different allocation: the work
pointer and the loop counter swap between a register and a stack slot, and the record pointer
is spilled.

Cause: the Japanese source allocates the output string as a copy of the template:
`base = MSGDATA_AllocString(bank, table[i].value); obj = MSGDATA_AllocString(bank, table[i].value);`.
The value is read from the table again (not through the record pointer), so the record pointer
is not live across the calls and the allocator colours the loop differently. English uses
`STRBUF_Create(0x80, heap)` for `obj`.

Fix: put the two lines under `#if LANGUAGE == LANGUAGE_JAPANESE` with the English pair in the
`#else`. When the record pointer is only a CSE temp in Japanese (its spill slot sits below the
case-block locals), write `table[i].field` at every use and drop the named pointer; English
can keep the same text when it still verifies.

Found in: src/game/ov183/br_codein.c (BR_CODEIN_ListSetupRowA..D, BR_CODEIN_ResultSetupRowA..C,
BR_CODEIN_RecordSetupProfile).
