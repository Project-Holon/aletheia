/*
 * function: func_02062474
 * address:  0x02062474
 * packet:   pkt_02062474
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146BB0       0x02146BB0  data
 *   g_020A8148       0x020A8148  data
 *   g_020A814C       0x020A814C  data
 *   func_020625D8    0x020625D8  arm
 *   func_020624C8    0x020624C8  arm
 *   func_02062594    0x02062594  arm

 * Blocking class: evidence (`literal`/`label`).  Every concrete byte is right; the
 * one unresolved site is the ABS32 for the data object at 0x020624C8 at 0x020624B8
 * (the pool word that installs the descriptor's function pointer).  0x020624C8 is
 * named by this pool word only -- nothing branches to it and no other pool
 * repeats it -- so `literal` discards its only witness and `label` does not
 * apply.  Every other site of this file resolves: 0x02146BB0 `literal x20`,
 * 0x020A8148 `literal x15`, 0x02062594 `label x5` and 0x020A814C `literal x15`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Hdr02062474 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

extern struct Hdr02062474 g_02146BB0;
extern u32 g_020A8148;
extern u32 g_020A814C;
extern void func_020625D8(void);
extern u32 func_020624C8(u32 size, u32 flag);
extern int func_02062594(u32 id);

void func_02062474(u32 a, u32 b, u32 c, u32 d)
{
    g_02146BB0.unk8 = a;
    g_02146BB0.unkC = b;
    g_02146BB0.unk10 = c;
    func_020625D8();
    if (d == 0) {
        return;
    }
    g_020A8148 = (u32)func_020624C8;
    g_020A814C = (u32)func_02062594;
}
