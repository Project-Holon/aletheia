/*
 * function: func_021C5C8C
 * address: 0x021C5C8C
 * packet: pkt_ov127_021C5C8C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04 wD3 lane14: complete draft, 337 bytes differ (frame 0x54 vs 0x4c, so every slot shifts). Structure matches the listing: mode=func_021C5E14(width,height); mode 0 forwards all args to func_020410D0; else tiled blit with 32-wide wrap, outer loop over rows (hh s8 remaining, n rows this chunk), inner loop over columns (cw, m), func_021C5E2C(q,tx,ty,mode,width,height,out) then func_020410D0(layer,x,y,m,n,ptr,ox,oy,out0,out1). Listing facts: original stack words 0x60,0x64,0x6c (w,h,sx) are read as bytes (ldrb for the call, ldrsb for the s8 loop copies), while q,sy,width,height (0x68,0x70,0x74,0x78) are copied ldr/str in the prologue and passed raw (no u8 truncation) in the first func_020410D0 call; the second call truncates oy,out0,out1 with lsls/lsrs 24. sy>>5 uses a plain shift (lsls 19, asrs 24) while cs/32 uses the signed-divide bias, and sy%32 uses the signed idiom. Tried: u8 params for all (this file), int sy,width,height (e2: callee then truncates at the first call, 373 bytes). Next: find a prototype for func_020410D0 whose last three params are not truncated in call 1 but are in call 2, and reduce the locals to the 0x4c frame (original slots 0x18..0x44: layer,y,mode,hh,n,ty,ox,oy,cs,ccx,cw copies).
 * symbols:
 *   func_021C5E14 0x021C5E14 thumb ov127
 *   func_021C5E2C 0x021C5E2C thumb ov127
 *   func_020410D0 0x020410D0 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021C5E14(unsigned, unsigned);
extern char *func_021C5E2C(char *, int, int, unsigned, s16, s16, u16 *);
extern void func_020410D0(u8, u32, u32, u32, u8, void *, u8, u8, u8, u8);
void func_021C5C8C(void *p, u8 layer, u8 x, u8 y, u8 w, u8 h, void *q, u8 sx, u8 sy, u8 width, u8 height)
{
    u16 out[2];
    int mode = func_021C5E14(width, height);
    s8 hh, ww, cs, cx, n, m, ox, oy, tx, ty;
    s8 cw, ccs, ccx;
    if (mode == 0) {
        func_020410D0(layer, x, y, w, h, q, sx, sy, width, height);
        return;
    }
    hh = h;
    if (hh <= 0) return;
    ww = w;
    cs = sx;
    cx = x;
    do {
        oy = sy % 32;
        if (oy + hh <= 32) {
            n = hh;
            hh = 0;
        } else {
            n = 32 - oy;
            hh = hh - n;
        }
        ty = sy / 32;
        ccs = cs;
        ccx = cx;
        cw = ww;
        while (cw > 0) {
            ox = ccs % 32;
            if (ox + cw <= 32) {
                m = cw;
                cw = 0;
            } else {
                m = 32 - ox;
                cw = cw - m;
            }
            tx = ccs / 32;
            func_020410D0(layer, ccx, y, m, n,
                func_021C5E2C(q, (u8)tx, (u8)ty, mode, width, height, out),
                ox, oy, out[0], out[1]);
            ccs = ccs + m;
            ccx = ccx + m;
        }
        sy = sy + n;
        y = y + n;
    } while (hh > 0);
}
