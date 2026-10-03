/*
 * function: func_021E0808
 * address: 0x021E0808
 * packet: pkt_ov183_021E0808
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021E3974 0x021E3974 data a4
 */
extern void func_02034714(void *,int,void *);
extern void func_02045808(void *);
extern void func_020307B0(void *);
extern char d_021E3974[];
void func_021E0808(char *p){if(!*(void **)(p+0x18))func_02034714(d_021E3974,0,d_021E3974);if(!p)func_02034714(d_021E3974,0,d_021E3974);func_02045808(*(void **)(p+0x18));func_020307B0(p);}
