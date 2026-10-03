/*
 * function: func_021F4CE4
 * address: 0x021F4CE4
 * packet: pkt_ov135_021F4CE4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027858 0x02027858 thumb
 *   func_02027FD8 0x02027FD8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02027858(void *);
extern void func_02027FD8(void *);
void func_021F4CE4(char *p) { if(*(void **)(p+0xe08)) { func_02027858(*(void **)(p+0xe08)); *(void **)(p+0xe08)=0; } if(*(void **)(p+0xe04)) { func_02027FD8(*(void **)(p+0xe04)); *(void **)(p+0xe04)=0; } }
