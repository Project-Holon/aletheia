/*
 * function: func_021F6720
 * address: 0x021F6720
 * packet: pkt_ov215_021F6720
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021F6AB4 0x021F6AB4 thumb ov215
 *   func_021F6AB8 0x021F6AB8 thumb ov215
 *   func_021F6AEC 0x021F6AEC thumb ov215
 *   func_021F6DB4 0x021F6DB4 thumb ov215
 *   func_021F6EF8 0x021F6EF8 thumb ov215
 *   func_021F6F64 0x021F6F64 thumb ov215
 *   d_021F73F4 0x021F73F4 data a4
 *   d_021F7340 0x021F7340 data a4
 *   d_021F7314 0x021F7314 data a4
 */
typedef unsigned short u16;
extern const char d_021F73F4[];
extern const unsigned d_021F7340[],d_021F7314[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern unsigned func_02017E1C(void *,unsigned,void *);
extern void *func_020056A0(void (*)(void),void *,unsigned);
extern void func_021F6AB4(void);
extern void func_021F6AB8(void *);
extern void func_021F6AEC(void *);
extern char *func_021F6DB4(unsigned,unsigned,const void *);
extern void func_021F6EF8(void *);
extern void func_021F6F64(void *);
char *func_021F6720(unsigned heap,void *mon)
{
    char *p;
    p=func_02030734(heap,96,1,d_021F73F4,433);
    *(u16 *)p=heap;
    *(void **)(p+4)=mon;
    *(u16 *)(p+8)=func_02017E1C(mon,5,0);
    *(int *)(p+12)=0;
    *(int *)(p+16)=0;
    *(int *)(p+20)=0;
    *(int *)(p+24)=0;
    *(int *)(p+28)=0;
    *(int *)(p+36)=0;
    *(int *)(p+40)=0;
    *(void **)(p+44)=func_020056A0(func_021F6AB4,p,1);
    func_021F6AB8(p);
    func_021F6AEC(p);
    if(*(u16 *)(p+8)==490)
        *(void **)(p+68)=func_021F6DB4(*(u16 *)p,5,d_021F7340);
    else
        *(void **)(p+68)=func_021F6DB4(*(u16 *)p,3,d_021F7314);
    func_021F6EF8(p);
    func_021F6F64(p);
    return p;
}
