/*
 * function: func_021D8C90
 * address: 0x021D8C90
 * packet: pkt_ov129_021D8C90
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9E48 0x021D9E48 thumb ov129
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_021DA320 0x021DA320 thumb ov129
 *   func_021D97CC 0x021D97CC thumb ov129
 *   func_021D97FC 0x021D97FC thumb ov129
 *   func_021D9E60 0x021D9E60 thumb ov129
 *   func_021D97B8 0x021D97B8 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 *   d_021DA830 0x021DA830 data a4
 *   d_021DA84C 0x021DA84C data a4
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef struct { s16 x,y; } Pair;
typedef struct { int x,y; } Scale;
extern const int d_021DA830[], d_021DA84C[];
extern void func_021D9E48(char *,int,int);
extern void func_0204B454(void *,Pair *,unsigned);
extern void func_0204B404(void *,Pair *,unsigned);
extern void func_0204B5AC(void *,Scale *);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021DA158(int x, int flag);
extern void func_021DA320(char *);
extern int func_021D97CC(char *,int);
extern int func_021D97FC(char *,int);
extern void func_021D9E60(char *,int);
extern void func_021D97B8(char *);
extern void func_021D8AF4(char *,int);
int func_021D8C90(char *p)
{
    int i,n;
    char *q;
    Scale scale;
    Pair first,second;
    switch(*(int *)(p+0x234)) {
    case 0:
        func_021D9E48(p,0,0);
        for(i=0;i<*(int *)(p+0x23c);i++) {
            q=p+i*28;
            if(*(u8 *)(q+24)) {
                func_0204B454(*(void **)(q+12),&first,0);
                first.x+=*(s16 *)(q+20);
                first.y+=*(s16 *)(q+22);
                func_0204B404(*(void **)(q+12),&first,0);
                (*(u8 *)(q+24))--;
                if(i>=*(int *)(p+0x248) && i<*(int *)(p+0x24c)) {
                    scale.x=d_021DA830[*(u8 *)(q+25)];
                    scale.y=scale.x;
                    func_0204B5AC(*(void **)(q+12),&scale);
                    (*(u8 *)(q+25))++;
                }
                if(i>=*(int *)(p+0x250) && i<*(int *)(p+0x254)) {
                    scale.x=d_021DA84C[*(u8 *)(q+25)];
                    scale.y=scale.x;
                    func_0204B5AC(*(void **)(q+12),&scale);
                    (*(u8 *)(q+25))++;
                }
            }
        }
        for(i=0;i<2;i++) {
            q=p+i*28;
            if(*(u8 *)(q+0x168)) {
                func_0204B454(*(void **)(q+0x15c),&second,0);
                second.x+=*(s16 *)(q+0x164);
                second.y+=*(s16 *)(q+0x166);
                func_0204B404(*(void **)(q+0x15c),&second,0);
                (*(u8 *)(q+0x168))--;
            }
        }
        if(*(u8 *)(p+24)==0) {
            for(i=*(int *)(p+0x248);i<*(int *)(p+0x24c);i++) {
                q=p+i*28;
                func_0204B878(*(void **)(q+12),func_021DA158(*(int *)q,*(int *)(q+8)));
            }
            for(i=*(int *)(p+0x250);i<*(int *)(p+0x254);i++) {
                q=p+i*28;
                func_0204B878(*(void **)(q+12),func_021DA158(*(int *)q,*(int *)(q+8)));
            }
            (*(int *)(p+0x234))++;
        }
        (*(int *)(p+0x238))++;
        break;
    case 1:
        for(i=*(int *)(p+0x248);i<*(int *)(p+0x24c);i++) {
            q=p+i*28;
            if(*(u8 *)(q+25)!=6) {
                scale.x=d_021DA830[*(u8 *)(q+25)];
                scale.y=scale.x;
                func_0204B5AC(*(void **)(q+12),&scale);
                (*(u8 *)(q+25))++;
            }
        }
        for(i=*(int *)(p+0x250);i<*(int *)(p+0x254);i++) {
            q=p+i*28;
            if(*(u8 *)(q+25)!=6) {
                scale.x=d_021DA84C[*(u8 *)(q+25)];
                scale.y=scale.x;
                func_0204B5AC(*(void **)(q+12),&scale);
                (*(u8 *)(q+25))++;
            }
        }
        (*(int *)(p+0x238))++;
        if(*(int *)(p+0x238)==6) (*(int *)(p+0x234))++;
        break;
    default:
        func_021DA320(p);
        if(*(int *)(p+0x324)==0) n=func_021D97CC(p,*(int *)(p+0x320));
        else n=func_021D97FC(p,*(int *)(p+0x320));
        func_021D9E60(p,n);
        if(*(int *)(p+0x240)) func_021D9E48(p,0,1);
        func_021D97B8(p);
        func_021D8AF4(p,1);
        break;
    }
    return 0;
}
