/*
 * function: func_02185728
 * address: 0x02185728
 * packet: pkt_ov219_02185728
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_02185F00 0x02185F00 data a4
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 */
typedef unsigned short u16;
typedef struct {unsigned x,y,z;} Vec3;
typedef struct {Vec3 vec;short x,y;} Config;
extern Vec3 d_02185F00,d_02185E0C,d_02185DF4;
extern Config d_020A1EB8;
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,Vec3 *,Vec3 *,Vec3 *,u16);
extern void func_02048AD0(void *);
void func_02185728(char *p)
{
    Vec3 vec;
    u16 heap;
    heap=*(unsigned *)p;
    vec=d_02185F00;
    *(void **)(p+0xC36C)=func_02048A24(0,d_020A1EB8.x,d_020A1EB8.y,5461,0,4096,4194304,0,&d_02185E0C,&vec,&d_02185DF4,heap);
    func_02048AD0(*(void **)(p+0xC36C));
}
