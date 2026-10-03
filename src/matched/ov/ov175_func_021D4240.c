/*
 * function: func_021D4240
 * address: 0x021D4240
 * packet: pkt_ov175_021D4240
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov177_id 0x000000B1 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034714 0x02034714 arm
 *   d_021E2C74 0x021E2C74 data a4
 *   d_021E2C80 0x021E2C80 data a4
 *   d_021E2DE0 0x021E2DE0 data
 */
typedef int (*Callback)(int,int,int *,int);
typedef struct { Callback create,other,close; } Table;
extern const Table d_021E2C74,d_021E2C80;
extern const char d_021E2DE0[];
extern const char ov177_id[];
typedef signed int     s32;
typedef unsigned int   u32;
extern int func_02034AC4(s32 handle);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_021D4240(int a,int b,int *p,int d)
{
    func_02034AC4((int)ov177_id);
    switch(((int *)p[2])[2]) {
    case 1: return d_021E2C74.create(a,b,p,d);
    case 0: return d_021E2C80.create(a,b,p,d);
    default: func_02034714(d_021E2DE0,0,d_021E2DE0); return 0;
    }
}
