/*
 * function: func_021BB180
 * address: 0x021BB180
 * packet: pkt_ov100_021BB180
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: BA00 tail forwards to D768; full D768 body reads state at0,
 *   words at4/8 for state0, and never the uninitialized padding at2 in that arm.
 * lever: b before a places their Word locals at sp+4 and sp+0 respectively.
 * symbols:
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021BA3A4 0x021BA3A4 thumb ov100
 *   func_021BA64C 0x021BA64C thumb ov100
 *   func_0204BA00 0x0204BA00 arm
 *   func_02040588 0x02040588 arm
 *   func_021BB0C4 0x021BB0C4 thumb ov100
 *   func_021BB10C 0x021BB10C thumb ov100
 *   d_021BB69C 0x021BB69C data a4
 *   d_021BB68C 0x021BB68C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Word { int x; };
struct Task { u16 state,pad; int context; void (*callback)(int); };
extern const struct Word d_021BB69C,d_021BB68C;
extern void func_021BA5F4(int);
extern void func_021BA3A4(struct Word *,int);
extern void func_021BA64C(int,int);
extern void func_0204BA00(int,struct Task *);
extern void func_02040588(int,int);
extern void func_021BB0C4(int),func_021BB10C(int);
void func_021BB180(int p)
{
    struct Word b,a;
    struct Task task;
    func_021BA5F4(p);
    if(*(int *)(p+0xc8c)==1) {
        if(*(int *)(p+0xc7c)) {
            b=d_021BB69C;
            func_021BA3A4(&b,p);
        } else {
            a=d_021BB68C;
            func_021BA3A4(&a,p);
            func_021BA64C(p,0);
            func_021BA64C(p,2);
        }
        func_021BA64C(p,6);
        func_021BA64C(p,7);
        func_021BA64C(p,4);
        func_021BA64C(p,5);
        func_021BA64C(p,1);
        func_021BA64C(p,3);
        if(*(int *)(p+0xc7c)) {
            task.state=0;
            task.context=p;
            task.callback=func_021BB0C4;
            func_0204BA00(*(int *)(p+0x2c8),&task);
            task.callback=func_021BB10C;
            func_0204BA00(*(int *)(p+0x2d0),&task);
        }
        *(int *)(p+0xc8c)=0;
    }
    *(int *)(p+0xc98)=(int)(*(u32 *)(p+0xc98)+1);
    if(*(int *)(p+0xc98)>8 && *(int *)(p+0xcec)) {
        *(int *)(p+0xc94)=0;
        func_02040588(1,0);
    }
}
