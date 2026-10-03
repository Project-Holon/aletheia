/*
 * function: func_021BD948
 * address: 0x021BD948
 * packet: pkt_ov216_021BD948
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: explicit case 3 plus default preserves four switch arms; BD7D4 u8 index preserves the original XOR truncation pair, own int index notwithstanding.
 * symbols:
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B64A8 0x021B64A8 thumb ov067
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021BD7D4 0x021BD7D4 thumb ov216
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BD448 0x021BD448 thumb ov216
 *   func_02031194 0x02031194 arm
 *   d_021BDD88 0x021BDD88 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct TcblNode;
struct Obj;
struct PrintSys;
extern int func_021B6448(u8 *);
extern void func_021B64A8(u8 *,u32);
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_021BD7D4(char *,u8,int,u8,int *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021BD448(void *);
extern void func_02031194(struct TcblNode *);
extern const u8 d_021BDD88[];
void func_021BD948(struct TcblNode *task,char *work)
{
    if(*(u8 *)(work+5)==0) {
        if(func_021B6448(*(u8 **)(*(char **)(work+16)+0x124))!=-1)
            *(u8 *)(work+5)=1;
    }
    if(func_0201C6B4(*(struct PrintSys **)(*(char **)(work+16)+0x12c))==0) return;
    switch(*(u8 *)work) {
    case 0:
        if(*(u8 *)(work+5)==0) break;
        func_021B64A8(*(u8 **)(*(char **)(work+16)+0x124),0);
        ++*(u8 *)work;
        return;
    case 1:
        func_021BD7D4(*(char **)(work+16),*(u8 *)(*(char **)(work+16)+0x2e),1,*(u8 *)(work+4),(int *)(work+8));
        func_021BD7D4(*(char **)(work+16),*(u8 *)(*(char **)(work+16)+0x2e)^1,d_021BDD88[*(u8 *)(work+4)],*(u8 *)(work+4),(int *)(work+8));
        func_0204B3DC(*(struct Obj **)(*(char **)(work+16)+0x264),0);
        func_0204B3DC(*(struct Obj **)(*(char **)(work+16)+0x268),0);
        ++*(u8 *)work;
        return;
    case 2:
        if(*(int *)(work+8)!=0) break;
        *(u8 *)(*(char **)(work+16)+0x2e)^=1;
        *(u8 *)(*(char **)(work+16)+0x30)=*(u8 *)(work+3);
        func_021BD448(*(void **)(work+16));
        ++*(u8 *)work;
        return;
    case 3:
    default:
        --**(int **)(work+20);
        func_02031194(task);
        break;
    }
}
