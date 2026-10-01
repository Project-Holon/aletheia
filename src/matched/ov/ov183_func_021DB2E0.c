/*
 * function: func_021DB2E0
 * address: 0x021DB2E0
 * packet: pkt_ov183_021DB2E0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD940 0x021FD940 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021DB3C4 0x021DB3C4 thumb ov183
 *   func_021DB594 0x021DB594 thumb ov183
 *   func_021DB61C 0x021DB61C thumb ov183
 */
extern unsigned func_021F9B9C(void *);
extern char *func_0203159C(int *,unsigned,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_0201C440(unsigned);
extern void *func_021FD760(int,int,int,unsigned);
extern void func_021FD940(void *,int);
extern void *func_021FD6D8(void *,void *,unsigned);
extern void func_021DB3C4(void);
extern void func_021DB594(void);
extern void func_021DB61C(void);
int func_021DB2E0(int *task, int unused, char *p)
{
    char *s;
    void *callback;
    s=func_0203159C(task,0x20,func_021F9B9C(*(void **)(p+0x10)));
    func_02082BCC(s,0,0x20);
    *(char **)(s+0x1c)=p;
    *(unsigned short *)(s+4)=func_021F9B9C(*(void **)(p+0x10));
    *(void **)(s+0xc)=func_0201C440(*(unsigned short *)(s+4));
    *(void **)(s+0x14)=func_021FD760(*(int *)(p+4),*(int *)(p+0xc),0,*(unsigned short *)(s+4));
    *(void **)(s+0x18)=func_021FD760(*(int *)(p+4),*(int *)(p+0xc),1,*(unsigned short *)(s+4));
    func_021FD940(*(void **)(s+0x14),1);
    func_021FD940(*(void **)(s+0x18),1);
    if(*(int *)p==0) callback=func_021DB3C4;
    else if(*(int *)p==1) callback=func_021DB594;
    else callback=func_021DB61C;
    *(void **)s=func_021FD6D8(s,callback,*(unsigned short *)(s+4));
    return 1;
}
