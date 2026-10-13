/*
 * function: func_021BCE98
 * address: 0x021BCE98
 * packet: pkt_ov209_021BCE98
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ov067 region follows the paired loader path 021BCC94/021BCD48.
 * 021B93D4's value is full width here: original subtract feeds r1 without narrowing.
 * symbols:
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   func_021BE5D4 0x021BE5D4 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_021BD2C4 0x021BD2C4 thumb ov209
 *   func_021BE4A8 0x021BE4A8 thumb ov209
 *   func_021BE658 0x021BE658 thumb ov209
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   func_021BD2F4 0x021BD2F4 thumb ov209
 *   func_021BD340 0x021BD340 thumb ov209
 *   func_021BD314 0x021BD314 thumb ov209
 *   func_021BD354 0x021BD354 thumb ov209
 *   func_021BE588 0x021BE588 thumb ov209
 *   func_021BE43C 0x021BE43C thumb ov209
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200CA5C 0x0200CA5C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Input {u32 a;void *save;u32 b,c,state;};
struct Context {struct Input *in;u8 pad4[0x10];u32 state;u8 pad18[0xc24-0x18];u16 flags;u8 padc26[6];void *list;};
struct Blk37;
struct S;
extern int FRAME_LIST_Update(struct S *p);
extern void func_021BE5D4(char *p, int flag);
extern void func_021BD890(char *p, int idx, int value);
extern int func_021BD2C4(char *p, int a, int b, int c);
extern void func_021BE4A8(char *p);
extern int func_021BE658(void *ctx_);
extern int FRAME_LIST_GetSelectedIndex(char *p);
extern int FRAME_LIST_GetScrollPos(char *p);
extern void FRAME_LIST_SetCursor(struct S *s, int v);
extern int func_021BD2F4(char *p, int i);
extern int func_021BD340(char *a, int arg);
extern void func_021BD314(char *p, int i);
extern void func_021BD354(char *p);
extern void func_021BE588(char *p);
extern void func_021BE43C(char *p);
extern u8 func_020355C4(void);
extern void func_020355D8(u8);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_0200CA5C(struct Blk37 *p, u32 v);
int func_021BCE98(struct Context *p)
{
    int result=4;
    int selected;
    u32 action;
    u8 old;
    switch(FRAME_LIST_Update(p->list)){
    case -12: break;
    case -11:case -10:case -9:case -8:
        func_021BE5D4((char *)p,0);break;
    case -7:
        func_021BD890((char *)p,7,12);
        p->flags=(p->flags&~0xfffe)|14;p->state=0;result=5;break;
    case -6:
        func_021BD890((char *)p,6,13);
        p->flags=(p->flags&~0xfffe)|12;p->state=0;result=5;break;
    case -5:return func_021BD2C4((char *)p,7,12,4);
    case -4:return func_021BD2C4((char *)p,6,13,4);
    case -3:case -2:
        func_021BE4A8((char *)p);
        p->flags=(p->flags&~0xfffe)|120;p->state=1;result=5;break;
    case -1:
        old=func_020355C4();
        action=func_021BE658(p);
        switch(action){
        case 0:
            selected=FRAME_LIST_GetSelectedIndex(p->list);
            if(func_021BD2F4((char *)p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return func_021BD340((char *)p,selected);}
            func_020355D8(old);break;
        case 1:case 2:case 3:case 4:case 5:case 6:case 7:
            selected=action+FRAME_LIST_GetScrollPos(p->list)-1;
            if(func_021BD2F4((char *)p,selected)==1){
                GFL_USE_PlaySeDefaultVolume(1356);FRAME_LIST_SetCursor(p->list,action-1);return func_021BD340((char *)p,selected);
            }break;
        case 8:
            GFL_USE_PlaySeDefaultVolume(1356);p->in->state=4;
            func_021BD314((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return func_021BD2C4((char *)p,9,4,8);
        case 9:
            GFL_USE_PlaySeDefaultVolume(1356);
            if(func_0200CA70(p->in->save)==1)func_0200CA5C(p->in->save,0);else func_0200CA5C(p->in->save,1);
            p->in->state=2;
            func_021BD314((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return func_021BD2C4((char *)p,8,5,8);
        case 10:GFL_USE_PlaySeDefaultVolume(1606);func_021BD354((char *)p);break;
        case 11:
            GFL_USE_PlaySeDefaultVolume(1366);p->in->state=1;
            func_021BD314((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return func_021BD2C4((char *)p,4,8,8);
        case 12:
            GFL_USE_PlaySeDefaultVolume(1361);p->in->state=0;
            func_021BD314((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return func_021BD2C4((char *)p,3,9,8);
        case 13:
            GFL_USE_PlaySeDefaultVolume(1361);p->in->state=0;
            func_021BD314((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return func_021BD2C4((char *)p,3,9,8);
        }
        break;
    default:
        selected=FRAME_LIST_GetSelectedIndex(p->list);func_021BE5D4((char *)p,0);
        if(func_021BD2F4((char *)p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return func_021BD340((char *)p,selected);}
        break;
    }
    func_021BE588((char *)p);func_021BE43C((char *)p);return result;
}
