/*
 * unit: yes
 * function: func_021BDF7C, func_021BE028
 * address: 0x021BDF7C
 * packet: pkt_ov099_021BDF7C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BB42C 0x021BB42C thumb ov099
 *   func_021BB4D0 0x021BB4D0 thumb ov099
 *   func_021BB4EC 0x021BB4EC thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021BE26C 0x021BE26C thumb ov099
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1AC0 0x021C1AC0 thumb ov099
 *   func_021BE384 0x021BE384 thumb ov099
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   func_021BE538 0x021BE538 thumb ov099
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0204A648 0x0204A648 arm
 */
struct Bank;
struct Node;
struct Rec;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern void func_021BB42C(void *p);
extern void func_021BB4D0(char *p);
extern void func_021BB4EC(void *p);
extern int func_021B96CC(int *p);
extern void func_021BE26C(char *p);
extern int func_021C1A44(char *p);
extern void func_021C1AC0(char *p);
extern void func_021BE384(void *p);
extern void func_0204B084(void *p);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_021BB0B4(char *p);
extern void func_021BE538(char *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02045C04(struct Rec *rec);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201D83C(void *p);
extern void func_0204A648(void);
void func_021BDF7C(char *p)
{
    if (*(void **)p != 0) func_02030EAC(*(void **)p);
    func_021BB42C(p);
    func_021BB4D0(p);
    func_021BB4EC(p);
    if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
    if (func_021C1A44(p) == 1) func_021C1AC0(p);
    func_021BE384(p + 0x898);
    func_0204B084(*(void **)(p + 0x114));
    func_0204B1CC(*(void **)(p + 0x110));
    func_0204A5AC();
    func_021BB0B4(p);
    func_021BE538(p);
    func_020450C8();
    func_0203F9B4();
    func_02045C04(*(void **)(p + 0xe4));
    func_02045C04(*(void **)(p + 0xe0));
    func_0201ED04(*(void **)(p + 0xdc));
    func_0201D83C(*(void **)(p + 0xec));
    func_0201D83C(*(void **)(p + 0xe8));
}
void func_021BE028(void)
{
    func_0204A648();
}
