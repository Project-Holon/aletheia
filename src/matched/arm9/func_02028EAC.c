/*
 * Byte-correct, MATCH*-capped. NOT in the manifest; see src/pending/README.md.
 *
 * function: func_02028EAC
 * address:  0x02028EAC
 * packet:   pkt_02028DCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02028D54.c is now a manifest entry (matched class)
 * symbols:
 *   func_02028F18  0x02028F18  thumb
 *   func_02028F30  0x02028F30  thumb
 *   func_02028F48  0x02028F48  thumb
 *   func_02028F60  0x02028F60  thumb
 *   func_02028F7C  0x02028F7C  thumb
 *   func_02028F9C  0x02028F9C  thumb
 *   func_02028FB8  0x02028FB8  thumb
 *
 * Previously blocked at MATCH* on callees: func_02028F30 through func_02028FB8 reside in
 * unit_02028F18 (pkt_02028B50), but unit_02028F18's header only lists func_02028F18,
 * so the other internal functions have no external branch witness in the manifest.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct SoundParam2;

extern void func_02028F18(struct SoundParam2 *obj, u16 a1);
extern void func_02028F30(struct SoundParam2 *obj, u16 a1);
extern void func_02028F48(struct SoundParam2 *obj, u16 a1);
extern void func_02028F60(struct SoundParam2 *obj, u16 a1, u16 a2);
extern void func_02028F7C(struct SoundParam2 *obj, u32 a1, u16 a2, u16 a3);
extern void func_02028F9C(struct SoundParam2 *obj, u32 a1, u16 a2);
extern void func_02028FB8(struct SoundParam2 *obj, u16 a1);

void func_02028EAC(struct SoundParam2 *obj, struct Cmd *cmd)
{
    switch (cmd->unk00) {
    case 1:
        func_02028F18(obj, cmd->unk0A);
        break;
    case 2:
        func_02028F30(obj, cmd->unk08);
        break;
    case 3:
        func_02028F48(obj, cmd->unk08);
        break;
    case 4:
        func_02028F60(obj, cmd->unk08, cmd->unk0A);
        break;
    case 5:
        func_02028F7C(obj, cmd->unk04, cmd->unk08, cmd->unk0A);
        break;
    case 6:
        func_02028F9C(obj, cmd->unk04, cmd->unk08);
        break;
    case 7:
        func_02028FB8(obj, (u16)cmd->unk04);
        break;
    default:
        break;
    }
}
