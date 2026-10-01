/*
 * function: func_021D429C
 * address: 0x021D429C
 * packet: pkt_ov175_021D429C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov177_id 0x000000B1 data
 *   func_02006210 0x02006210 thumb
 *   func_02034A5C 0x02034A5C arm
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
extern void func_02034A5C(int);
extern void func_02034714(const char *,int,const char *);
extern void func_02006210(void);
int func_021D429C(int a,int b,int *p,int d)
{
    int result;
    switch(((int *)p[2])[2]) {
    case 1: result=d_021E2C74.close(a,b,p,d); break;
    case 0: result=d_021E2C80.close(a,b,p,d); break;
    default: func_02034714(d_021E2DE0,0,d_021E2DE0); break;
    }
    func_02006210();
    func_02034A5C((int)ov177_id);
    return result;
}
