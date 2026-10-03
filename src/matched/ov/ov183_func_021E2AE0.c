/*
 * function: func_021E2AE0
 * address: 0x021E2AE0
 * packet: pkt_ov183_021E2AE0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Declare scalar locals before Pair; assign the returned Pair as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 * symbols:
 *   func_021E2E60 0x021E2E60 thumb ov183
 *   func_021E2E30 0x021E2E30 thumb ov183
 *   func_021E2E48 0x021E2E48 thumb ov183
 *   func_021E31E8 0x021E31E8 thumb ov183
 *   func_021E3228 0x021E3228 thumb ov183
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021E2C2C 0x021E2C2C thumb ov183
 *   func_021E2910 0x021E2910 thumb ov183
 */
typedef struct Pair {int a,b;} Pair;
extern void func_021E2E60(Pair *);
extern void func_021E2E30(char *,int,int),func_021E2E48(char *,char *,char *);
extern int func_021E31E8(char *,int,int),func_021E3228(char *,int,int);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *),func_02035D20(unsigned *,unsigned *);
extern void func_021FD73C(int *,int);
extern void func_021E2C2C(void),func_021E2910(void);
void func_021E2AE0(int *task,unsigned *state,char *p)
{
    unsigned x,y;
    Pair a;
    switch(*state) {
    case 0:
        func_021E2E60(&a);
        *(Pair *)(p+0x4c)=a;
        func_021E2E30(p+0x4c,(int)p,*(int *)(p+0x3c));
        ++*state; break;
    case 1:
        func_021FE784(**(int **)(p+0x3c),2,3,0);
        ++*state; break;
    case 2:
        if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;
        break;
    case 3:
        if(func_02035D20(&x,&y)) {
            if(func_021E31E8(p,x,y)) *state=4;
            if(func_021E3228(p,x,y)) *state=7;
        }
        break;
    case 4:
        func_021FE784(**(int **)(p+0x3c),2,3,1);
        ++*state; break;
    case 5:
        if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;
        break;
    case 6:
        func_021E2E48(p+0x4c,p,*(char **)(p+0x3c));
        func_021FD73C(task,(int)func_021E2C2C); break;
    case 7:
        func_021FE784(**(int **)(p+0x3c),2,3,1);
        ++*state; break;
    case 8:
        if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;
        break;
    case 9:
        func_021E2E48(p+0x4c,p,*(char **)(p+0x3c));
        func_021FD73C(task,(int)func_021E2910); break;
    }
}
