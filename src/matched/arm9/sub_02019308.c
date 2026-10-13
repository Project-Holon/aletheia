/*
 * function: POKE_TOOL_SetPartyValueRaw
 * address:  0x02019308
 * packet:   pkt_02018DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The setter twin of POKE_TOOL_GetPartyValueRaw (src/matched/POKE_TOOL_GetPartyValueRaw.c): the same
 * twelve party-area ids 0x9D to 0xA8 over the same offsets of the 0xDC byte
 * record, with everything else forwarded to POKE_TOOL_SetBoxValueRaw, the 178 case
 * writer over the block area (src/matched/POKE_TOOL_SetBoxValueRaw.c).
 *
 * Two details cost the time here and both are about where the two ids that
 * store nothing send control.
 *
 * The forwarding call has to be written as `default:` inside the switch rather
 * than as a statement after it.  Written after the switch the compiler places
 * the forwarding block first, at the head of the case bodies, and every one of
 * the twelve table displacements moves.
 *
 * `case 0xA8` has to be an empty arm ending in `break`, not `return`.  Both
 * spellings produce the same twelve entry table and the same eleven bodies,
 * and they differ in one byte: the twelfth displacement.  With `break` the
 * empty arm lands on the function's last `pop`, the one the forwarding call
 * falls into; with `return` it lands on the `pop` that ends case 0xA7's body
 * instead, four bytes earlier.  The original names the last one.
 *
 * Nothing here is version specific.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_SetPartyValueRaw.c \
 *       --func POKE_TOOL_SetPartyValueRaw --addr 0x02019308 --cc 1.1p1
 *
 * symbols:
 *   MAIL_Copy   0x02008F3C  thumb
 *   POKE_TOOL_SetBoxValueRaw  0x02019388  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mail {
    u8 unk00[0x38];
};

struct Mon {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
    u32 unk88;
    u8  unk8C;
    u8  unk8D;
    u16 unk8E;
    u16 unk90;
    u16 unk92;
    u16 unk94;
    u16 unk96;
    u16 unk98;
    u16 unk9A;
    struct Mail unk9C;
};

struct Sub02008F80Obj;
extern void MAIL_Copy(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest);
extern void POKE_TOOL_SetBoxValueRaw(struct Mon *p, u32 id, u32 v);

void POKE_TOOL_SetPartyValueRaw(struct Mon *p, u32 id, u32 v)
{
    switch (id) {
    case 0x9D: p->unk88 = v; return;
    case 0x9E: p->unk8C = (u8)v; return;
    case 0x9F: p->unk8D = (u8)v; return;
    case 0xA0: p->unk8E = (u16)v; return;
    case 0xA1: p->unk90 = (u16)v; return;
    case 0xA2: p->unk92 = (u16)v; return;
    case 0xA3: p->unk94 = (u16)v; return;
    case 0xA4: p->unk96 = (u16)v; return;
    case 0xA5: p->unk98 = (u16)v; return;
    case 0xA6: p->unk9A = (u16)v; return;
    case 0xA7:
        MAIL_Copy((const struct Sub02008F80Obj *)v, (struct Sub02008F80Obj *)(&p->unk9C));
        return;
    case 0xA8:
        break;
    default:
        POKE_TOOL_SetBoxValueRaw(p, id, v);
        break;
    }
}
