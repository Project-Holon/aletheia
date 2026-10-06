/*
 * function: func_0216EB68
 * address:  0x0216EB68
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_StopMatch: closes every connection, records the error and reports the failure to the match callback.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02172E7C  0x02172E7C  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02169038  0x02169038  arm  ov009
 *   func_0216F6C0  0x0216F6C0  arm  ov009
 */

typedef void (*MatchedCallback)(int error, int cancel, int self, int isServer, int index, void *param);

extern int func_02175F3C(void);
extern void func_02172E7C(void);
extern void DWCi_SetError(int error, int errorCode);
extern int func_0216F20C(int status);
extern int func_02169038(int pid);
extern void func_0216F6C0(void);

void func_0216EB68(int error, int errorCode)
{
    int self;
    int isServer;

    if (func_02175F3C() == 0 || error == 0) {
        return;
    }
    func_02172E7C();
    DWCi_SetError(error, errorCode);
    self = 1;
    func_0216F20C(self);
    if (*(int *)(func_02175F3C() + 0x680) != 0) {
        self = 0;
    }
    (*(MatchedCallback *)(func_02175F3C() + 0x770))(
        error, 0, self, *(unsigned char *)(func_02175F3C() + 0x14) == 2,
        func_02169038(*(int *)(func_02175F3C() + 0x680)), *(void **)(func_02175F3C() + 0x774));
    func_0216F6C0();
}
