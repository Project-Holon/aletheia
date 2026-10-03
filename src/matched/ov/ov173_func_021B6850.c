/*
 * function: func_021B6850
 * address: 0x021B6850
 * packet: pkt_ov173_021B6850
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021B6850(char *p) { *(void **)(p+0x44)=func_02045B38(0,2,204,79); *(void **)(p+0x48)=func_0201EC64(79); *(void **)(p+0x4c)=func_020457B0(256,79); *(void **)(p+0x50)=func_02045EC0(*(void **)(p+0x44),25); *(void **)(p+0x54)=func_02045EC0(*(void **)(p+0x44),31); }
