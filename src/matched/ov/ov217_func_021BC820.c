/*
 * function: func_021BC820
 * address: 0x021BC820
 * packet: pkt_ov217_021BC820
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes at 021BC8B2.
 * Initialize n after the getter expression; initializing in its declaration
 * schedules movs r5,#1 before both getters (14 concrete bytes differ).
 * symbols:
 *   func_021BC628 0x021BC628 thumb ov217
 * 021BC628 forwards to the +8 getter 021C09B4; its void source leaves r0
 * live and the original immediately feeds that result to 0201296C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern struct BigObj *func_021BC628(u8 *);
extern u32 func_0201296C(const struct BigObj *);
extern u32 func_020142E8(void *, int);
void func_021BC820(u8 *p)
{
    void *bitmap;
    int n;
    bitmap = (void *)func_0201296C(func_021BC628(p));
    n = 1;
    if (func_020142E8(bitmap, 240) == 1) n++;
    if (func_020142E8(bitmap, 241) == 1) n++;
    if (func_020142E8(bitmap, 242) == 1) n++;
    if (func_020142E8(bitmap, 243) == 1) n++;
    if (func_020142E8(bitmap, 244) == 1) n++;
    if (func_020142E8(bitmap, 245) == 1) n++;
    if (func_020142E8(bitmap, 246) == 1) n++;
    if (func_020142E8(bitmap, 247) == 1) n++;
    if (func_020142E8(bitmap, 248) == 1) n++;
    p[0x30] = n;
}
