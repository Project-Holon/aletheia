/*
 * function: func_021D9488
 * address: 0x021D9488
 * packet: pkt_ov121_021D9488
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA978 0x021DA978 thumb ov121
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021DA958 0x021DA958 thumb ov121
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void func_021DA978(char *p);
extern void func_021DA958(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void *func_021D6C58(u8 *p, int i);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BMP_OAM_DeleteSys(void *);
extern void MI_CpuFill8(void *,int,int);
void func_021D9488(void **p) {
 func_021DA978(p[1]);CLACT_SetActorDrawEnable(func_021D6C58(p[2],34),0);func_021DA958(p[1]);BMP_OAM_DeleteSys(p[0]);MI_CpuFill8(p,0,12);
}
