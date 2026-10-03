/*
 * function: func_021FFC9C
 * address: 0x021FFC9C
 * packet: pkt_ov186_021FFC9C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022000F0 0x022000F0 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FFFCC 0x021FFFCC thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_02200188 0x02200188 thumb ov186
 *   func_021FFFF8 0x021FFFF8 thumb ov186
 *   func_022000D0 0x022000D0 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   func_021FFF28 0x021FFF28 thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   d_02200DAC 0x02200DAC data
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
extern int func_022000F0(char *);
extern int func_02035D20(int *,int *);
extern int func_021FB4B4(int,int,int);
extern void func_021FD860(char *,u32,const Pair *);
extern void func_021FCD0C(char *);
extern int func_021FCDA8(char *),func_021FD938(char *),func_021FE7B0(int *);
extern void func_021FE784(void *,int,int,int);
extern void func_021FFFCC(char *),func_022000D0(char *),func_021FFF28(char *),func_021FFFF8(char *);
extern u16 *func_02200188(void *,u32,u16 *,u32 *,u16);
extern void func_02034714(const char *,int,const char *),func_020307B0(void *);
extern unsigned func_021FFE34(char *p);
extern char d_02200DAC[];
int func_021FFC9C(char *p)
{
    if (*(int *)(p+0x6c)) {
        switch (*(u32 *)p) {
        case 0: (*(u32 *)p)++; break;
        case 1: *(u32 *)p=2; break;
        case 2: {
            int x,y,held;
            Pair pair;
            *(int *)(p+0xc)=func_022000F0(p);
            held=func_02035D20(&x,&y);
            if (func_021FB4B4(*(int *)(p+0x2c),x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char **)(p+0x78),1,&pair);
                *(int *)p=8; *(int *)(p+8)=1;
            } else if (*(int *)(p+0xc)!=9) {
                *(int *)p=4; *(int *)(p+4)=3;
            }
            break;
        }
        case 3: {
            int x,y,held;
            Pair pair;
            func_021FCD0C(*(char **)(p+0x68));
            *(int *)(p+0x10)=func_021FCDA8(*(char **)(p+0x68));
            held=func_02035D20(&x,&y);
            if (func_021FB4B4(*(int *)(p+0x2c),x,y)&held) {
                pair.x=x; pair.y=y;
                func_021FD860(*(char **)(p+0x78),1,&pair);
                *(int *)p=4; *(int *)(p+4)=2;
            } else if (*(int *)(p+0x10)!=-1) {
                *(int *)p=8; *(int *)(p+8)=2;
            }
            break;
        }
        case 4:
            if (func_021FD938(*(char **)(p+0x78))) {
                func_021FE784(*(void **)(p+0x30),2,2,1);
                (*(u32 *)p)++;
            }
            break;
        case 5:
            if (func_021FE7B0(*(int **)(p+0x30))) (*(u32 *)p)++;
            break;
        case 6:
            if (*(int *)(p+4)==3) {
                func_021FFFCC(p);
                if (*(void **)(p+0x88)) func_02034714(d_02200DAC,0,d_02200DAC);
                *(u16 **)(p+0x88)=func_02200188(*(void **)(p+0x7c),*(u32 *)(p+0xc),*(u16 **)(p+0x80),(u32 *)(p+0x8c),*(u16 *)(p+0x24));
                func_021FFFF8(p);
            } else {
                func_022000D0(p);
                if (*(void **)(p+0x88)) {
                    func_020307B0(*(void **)(p+0x88));
                    *(void **)(p+0x88)=0;
                }
                func_021FFF28(p);
            }
            func_021FE784(*(void **)(p+0x30),2,2,0);
            (*(u32 *)p)++;
            break;
        case 7:
            if (func_021FE7B0(*(int **)(p+0x30))) *(u32 *)p=*(u32 *)(p+4);
            break;
        case 8: (*(u32 *)p)++; break;
        case 9: (*(u32 *)p)++; break;
        case 10: *(int *)(p+0x20)=1; break;
        }
    }
    return func_021FFE34(p);
}
