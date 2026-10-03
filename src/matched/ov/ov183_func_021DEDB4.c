/*
 * function: func_021DEDB4
 * address: 0x021DEDB4
 * packet: pkt_ov183_021DEDB4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF3DC 0x021DF3DC thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DED64 0x021DED64 thumb ov183
 *   func_021DF8F0 0x021DF8F0 thumb ov183
 *   func_021DF41C 0x021DF41C thumb ov183
 *   func_02034714 0x02034714 arm
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   d_021E3964 0x021E3964 data a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_021DF3DC(char *, int);
extern int func_02035D20(u32 *, u32 *);
extern int func_021FB4B4(int, int, int);
extern void func_021FD860(int, int, int *);
extern void func_021F9BA0(void *);
extern void func_021FD73C(int *, int);
extern void func_021DED64(void);
extern int func_021DF8F0(u32, u32);
extern u32 func_021DF41C(char *);
extern void func_02034714(const char *, u32, const char *);
extern void func_021F9BF4(unsigned *, unsigned);
extern const char d_021E3964[];
void func_021DEDB4(int *task, int *state, char *p)
{
    u32 x,y;
    func_021DF3DC(p+0x28,*(u16 *)(p+0x18));
    if (func_02035D20(&x,&y)) {
        if (func_021FB4B4(*(int *)(p+4),x,y)) {
            int args[2];
            args[0]=x; args[1]=y;
            func_021FD860(*(int *)(p+0x20),1,args);
            func_021F9BA0(*(void **)(*(char **)(p+0x108)+0x14));
            func_021FD73C(task,(int)func_021DED64);
        }
        if (func_021DF8F0(x,y)) {
            u32 selection;
            int args[2];
            selection=func_021DF41C(p+0x28);
            if (selection>=*(u32 *)(*(char **)(*(char **)(p+0x108)+0x1c)+0x1718))
                func_02034714(d_021E3964,0,d_021E3964);
            *(u32 *)(*(char **)(*(char **)(p+0x108)+0x1c)+0x171c)=selection;
            func_021F9BF4(*(unsigned **)(*(char **)(p+0x108)+0x14),2);
            func_021FD73C(task,(int)func_021DED64);
            args[0]=x; args[1]=y;
            func_021FD860(*(int *)(p+0x20),1,args);
        }
    }
}
