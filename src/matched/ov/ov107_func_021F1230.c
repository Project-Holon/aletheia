/*
 * function: func_021F1230
 * address: 0x021F1230
 * packet: pkt_ov107_021F1230
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov107/mb_comm_sys.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f00; u8 kind; } Msg_021F1230;
typedef struct { u8 pad[0x0C]; u32 f0c; u8 pad2[0x08]; u16 flags; u16 flags2; u8 f1c; u8 pad3; u16 f1e; u8 f20; u8 pad4[3]; u32 f24; } State_021F1230;
void func_021F1230(int a, int b, Msg_021F1230 *m, State_021F1230 *s);

void func_021F1230(int a, int b, Msg_021F1230 *m, State_021F1230 *s)
{
    switch (m->kind) {
    case 0: s->flags |= 0x4; break;
    case 1: s->flags |= 0x80; break;
    case 2: s->flags |= 0x100; s->f1c = *(u32 *)m; break;
    case 3: s->flags |= 0x200; s->f1c = *(u32 *)m; break;
    case 4: s->flags |= 0x400; break;
    case 5: s->f1e = *(u32 *)m; s->flags |= 0x1000; break;
    case 10: s->f0c = *(u32 *)m; break;
    case 11: s->flags |= 0x8; break;
    case 12: s->flags |= 0x10; break;
    case 13: s->flags |= 0x20; break;
    case 14: s->flags |= 0x40; break;
    case 15: s->flags |= 0x2000; s->f20 = *(u32 *)m; break;
    case 16:
        s->flags2 |= 0x4;
        s->flags2 = (s->flags2 & ~0x8) | (((u16)*(u32 *)m & 1) << 3);
        break;
    case 17: s->flags2 |= 0x10; break;
    case 18: s->flags2 |= 0x20; break;
    case 19: s->flags |= 0x4000; s->f24 = *(u32 *)m; break;
    case 20: s->flags |= 0x8000; break;
    case 21:
        s->flags2 = (s->flags2 & ~0x1) | 0x1;
        s->flags2 = (s->flags2 & ~0x2) | (((u16)*(u32 *)m & 1) << 1);
        break;
    }
}
