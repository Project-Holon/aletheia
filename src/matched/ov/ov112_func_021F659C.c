/*
 * function: func_021F659C
 * address: 0x021F659C
 * packet: pkt_ov112_021F659C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020648B4 0x020648B4 arm
 *   func_02064754 0x02064754 arm
 *   d_021F83D4 0x021F83D4 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u16,u32,int,const char *,u16);
extern int func_020648B4(u32,u32);
extern void func_02064754(char *,char *,void *,int,void *,int);
extern const char d_021F83D4[];
void func_021F659C(char *p, int kind)
{
    *(void **)(p+140)=func_02030734(*(u32 *)(p+244),func_020648B4(*(u32 *)(p+12),kind),0,d_021F83D4,1216);
    func_02064754(p+40,*(char **)(p+140),*(void **)(p+20),*(int *)(p+4),*(void **)(p+12),kind);
}
