/*
 * function: func_021DB698
 * address: 0x021DB698
 * packet: pkt_ov183_021DB698
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 * symbols:
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_021FC1F8 0x021FC1F8 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021F9CB8 0x021F9CB8 thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 */
extern char *func_0203159C(int *,int,unsigned);
extern void func_02082BCC(void *,int,int);
extern unsigned func_021F9B9C(char *);
extern void func_021FC1F8(int *,int);
extern void func_021FC148(int *,int,int);
extern void func_021FB964(int *,int,int);
extern int func_021FD760(int,int,int,int);
extern int func_021F9CB8(int,int,int,int,int,int,int);
extern void func_021FE840(int,int,int);
int func_021DB698(int *task,int b,char *p)
{
    char *s;
    s=func_0203159C(task,24,func_021F9B9C(*(char **)(p+0x1c)));
    func_02082BCC(s,0,24);
    *(char **)(s+0xc)=p;
    *(unsigned short *)(s+0x14)=func_021F9B9C(*(char **)(p+0x1c));
    func_021FC1F8(*(int **)(p+0x18),0);
    func_021FC1F8(*(int **)(p+0x18),1);
    func_021FC148(*(int **)(p+0x18),0,*(unsigned short *)(s+0x14));
    func_021FC148(*(int **)(p+0x18),1,*(unsigned short *)(s+0x14));
    if(*(int *)p<5) func_021FB964(*(int **)(p+0x18),3,*(unsigned short *)(s+0x14));
    else func_021FB964(*(int **)(p+0x18),4,*(unsigned short *)(s+0x14));
    *(int *)(s+4)=func_021FD760(*(int *)(p+0x14),*(int *)(p+0x18),1,*(unsigned short *)(s+0x14));
    *(int *)s=func_021F9CB8(*(int *)p,*(int *)(p+0x14),*(int *)(p+0x18),*(int *)(p+0x20),*(int *)(p+0x24),*(int *)(s+4),*(unsigned short *)(s+0x14));
    if(*(int *)(p+0xc)==4) func_021FE840(*(int *)(p+0x10),2,0);
    else func_021FE840(*(int *)(p+0x10),3,0);
    return 1;
}
