# ARM9 requests from the overlay session

The overlay session does not touch ARM9. These ARM9 items block overlay matches; they are for the ARM9 session.

| ARM9 address | what | unblocks |
|---|---|---|
| 0x02019CF8 | 8-byte Thumb tail-call thunk the listing decodes as ARM; witness bl at ov170 0x021DD750 | ov170 0x021DD718 (MATCH to EXACT) |
| 0x02015D30 | unlabelled Thumb leaf | ov094 0x022006B4 (MATCH to EXACT) |
| 0x02051790, 0x020517A4, 0x020517B4, 0x020517D0, 0x020517D8, 0x020517E0, 0x020517E8, 0x020517F0, 0x02051800, 0x02051808, 0x02051818, 0x02051820, 0x02051830 | unlabelled accessor leaves called from ov094 0x021FD1CC | lifts the MATCH cap on ov094 0x021FD1CC |
| 0x02013DD0 | ARM9 veneer; witness bl at ov021 0x0218B224 | ov021 0x0218B208 (MATCH to EXACT) |
| 0x0200FB4C | unlabelled Thumb call target; witness in ov135 0x022010BC | ov135 0x022010BC (MATCH to EXACT, with four ov114 seeds) |
| 0x0200960C, 0x02009628 | ARM9 getters the listing prints as .word data; called from ov135 0x021F8554 | ov135 0x021F8554 (MATCH to EXACT) |

Prototype mismatches in ARM9 bodies seen from ov135 callers (bytes match either way): 0x0201F878 is called with 5 arguments but its body takes 4; 0x02031324 and 0x0203159C have their return values used but are declared void; 0x020185F4 is declared void(void) but receives and returns a value.
