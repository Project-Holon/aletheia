/*
 * function: func_0203EE18
 * address:  0x0203EE18
 * packet:   pkt_0203EE18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 * blocker:  s_020A7E28 (string) -- no witness outside 0203EE18..0203EF5C; format string "BufferSize is not enough!![%x][%x]\n" has embedded control characters preventing string class attestation.
 *
 * symbols:
 *   g_021469F4      0x021469F4  data
 *   s_020A7D74      0x020A7D74  data
 *   s_020A7E28      0x020A7E28  data
 *   func_02034734   0x02034734  arm
 *   func_020399A8   0x020399A8  arm
 *   func_0203D1A4   0x0203D1A4  arm
 *   func_0203D798   0x0203D798  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Channel {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkc;
    u8  flag : 1;
};

struct Cmd {
    u32 cmd : 2;
    u32 data : 30;
};

struct Manager {
    u32 unk0[15];
    u32 unk3c;
};

struct Obj7 {
    u8 pad[0x64];
    u8 unk64;
};

extern struct Channel **g_021469F4;
extern char s_020A7D74[];
extern char s_020A7E28[];

extern void func_02034734(const char *file, u32 line, const char *msg, ...);
extern u32  func_020399A8(void);
extern u32  func_0203D1A4(u32);
extern struct Obj7 *func_0203D798(void);

void func_0203EE18(u32 idx, u32 a1, struct Cmd *pVal, u32 a3, u32 a4)
{
    struct Obj7 *r7;

    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 == 0 || g_021469F4[idx] == 0) {
        return;
    }

    r7 = func_0203D798();
    if (g_021469F4 == 0 || g_021469F4[idx] == 0) {
        return;
    }

    if (a4 != func_020399A8()) {
        if (r7->unk64 == 0) {
            return;
        }
    }

    switch (pVal->cmd) {
    case 0:
        if (g_021469F4[idx]->unk4 < pVal->data) {
            func_02034734(s_020A7D74, 543, s_020A7E28, g_021469F4[idx]->unk4, pVal->data);
        }
        g_021469F4[idx]->unk8 = pVal->data;
        g_021469F4[idx]->unkc = 0;
        g_021469F4[idx]->flag = 0;
        break;

    case 1:
        if (g_021469F4[idx]->unkc == g_021469F4[idx]->unk8) {
            g_021469F4[idx]->flag = 1;
        }
        break;

    case 2:
        if (idx != func_0203D1A4(func_020399A8())) {
            ((struct Manager *)g_021469F4)->unk3c = 1;
        }
        break;
    }
}
