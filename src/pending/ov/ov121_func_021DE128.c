/*
 * function: func_021DE128
 * address: 0x021DE128
 * packet: pkt_ov121_021DE128
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave P23 lane 10): 7/44 bytes differ (older draft 11/44). Only b and c are
 *   swapped (image b r7, c r4, d r6, p r5; build b r4, c r7). Best form returns the halfword
 *   read back from +2 (the image leaves it in r0 at the pop): `t = *(u16 *)(p+2); ... *(u16 *)p = t; ... return t;`.
 *   Return type u16, int, int t, u32 c/d, load placed late: all 7. Return written as `r = *(u16 *)p = *(u16 *)(p+2)`
 *   or `return *(u16 *)p`: 11. Tried and flat at 11: six per-function pragmas, int callee size parameter,
 *   p as char *, c/d as u32. Worse: int b (truncation added, 34), short b (37), u16 pointer array (34),
 *   struct pointer for the c/d pairs (30), b store moved after the c/d stores (16).
 *   int b alone gives the image colours (b r7, c r4, d r6) but adds lsls/lsrs; the image has u16 b with no
 *   truncation. The only caller (ov121 021DD9CC) declares this function void and ignores the result.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *,int,u32);
u16 func_021DE128(u8 *p,u16 b,int c,int d)
{
    u16 t;
    func_02082BCC(p,0,44);
    *(u16 *)(p+2)=b;
    *(u16 *)(p+10)=11;
    t=*(u16 *)(p+2);
    *(u16 *)(p+4)=b;
    *(int *)(p+20)=c;
    *(int *)(p+24)=d;
    *(int *)(p+28)=c;
    *(int *)(p+32)=d;
    *(u16 *)p=t;
    *(int *)(p+36)=c;
    *(int *)(p+40)=d;
    return t;
}
