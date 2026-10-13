/*
 * file:     external_ex.c
 * unit:     yes
 * function: RTCEXi_CommonCallback
 * address:  0x02700000
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      librtcex.TWL.HYB.a external_ex.o
 *
 * 0x02FFFDEC is a fixed DSi hardware/ROM buffer address, so the original
 *   source read it through a cast constant (`ldr r3, =0x02FFFDEC`), the same
 *   shape as src/matched/func_01FF8460.c.  It is therefore a literal pool
 *   word, not a relocation, and needs no witness.
 *
 * symbols:
 *   func_020889F8  0x020889F8  arm twl a2
 */

typedef unsigned int u32;

extern void *func_020889F8(void);

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad00[8];
    void *dst;
    u8 pad0C[8];
    u32 kind;
    u32 result;
} Req02700000;

u32 RTCEXi_CommonCallback(void)
{
    Req02700000 *req = (Req02700000 *)func_020889F8();
    u32 ret = 0;

    switch (req->kind) {
    case 0x10: {
        u8 *src = (u8 *)0x02FFFDEC;
        *(u32 *)req->dst = src[0] | (src[1] << 8) | (src[2] << 16);
        break;
    }
    case 0x11:
        *(u16 *)req->dst = *(u16 *)0x02FFFDEC;
        break;
    case 0x12:
        break;
    default:
        req->result = 0;
        ret = 4;
        break;
    }
    return ret;
}
