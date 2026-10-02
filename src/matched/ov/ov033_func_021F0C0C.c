/*
 * function: func_021F0C0C
 * address: 0x021F0C0C
 * packet: pkt_ov033_021F0C0C
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_020215A0(void *,unsigned);
extern void func_02021540(void *);
extern void func_02030DA4(void *);
extern void func_020307B0(void *);
void func_021F0C0C(char *p) { func_020215A0(*(void **)(p+0xbc),1); func_020215A0(*(void **)(p+0xbc),3); func_02021540(*(void **)(p+0xbc)); func_02030DA4(*(void **)(p+0xb4)); func_020307B0(*(void **)(p+0xb8)); }
