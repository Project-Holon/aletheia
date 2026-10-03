/*
 * function: func_021B6498
 * address: 0x021B6498
 * packet: pkt_ov173_021B6498
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: inline helper with unsigned enum offset keeps base and offset pool order and word-load register; raw and signed-offset forms differed.
 * symbols:
 *   func_021B7908 0x021B7908 thumb ov173
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   d_02FE0000 0x02FE0000 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7908(char *);
extern void func_020419E4(void);
extern void func_0204A648(void);
typedef enum { FLAGS_OFFSET=0x3ff8, OFFSET_FORCE_UNSIGNED=0xffffffffu } SharedOffset;
extern u8 d_02FE0000[];
static inline void setShared(u32 base,SharedOffset off) { *(u32 *)(base+off)|=1; }
void func_021B6498(void *unused,char *p) { func_021B7908(p); func_020419E4(); func_0204A648(); setShared((u32)d_02FE0000,FLAGS_OFFSET); }
