/*
 * function: func_021BE8E8
 * address:  0x021BE8E8
 * packet:   pkt_ov114_021BE8E8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_SetBasicAuthorization (libnhttp.TWL.HYB.a(d_nhttp.o))
 *
 * symbols:
 *   func_021BEF08 0x021BEF08 arm ov114
 *   func_021BEF58 0x021BEF58 arm ov114
 *   func_021BEC10 0x021BEC10 arm ov114
 *   func_021BA124 0x021BA124 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_021BA100 0x021BA100 arm ov114
 *   func_021BA714 0x021BA714 arm ov114
 *   g_021CE53C 0x021CE53C data
 */

typedef struct {
    char pad[0x4c];
    char auth[0x5c];
    int authLen;
} Req;

extern char g_021CE53C[];

extern void *func_021BEF08(void);
extern void *func_021BEF58(void);
extern Req *func_021BEC10(void *mutexInfo_p, void *handle_p);
extern int func_021BA124(char *s, int max);
extern void func_021BA13C(void *p_p, int size);
extern void func_021BA100(void *dst_p, void *src_p, int size);
extern int func_021BA714(char *dst_p, char *src_p);

int func_021BE8E8(void *handle, char *username_p, char *password_p)
{
    char tmpbuf[65];
    int password_len;
    int username_len;
    Req *req_p;
    void *mutexInfo_p;

    func_021BEF08();
    mutexInfo_p = func_021BEF58();
    req_p = func_021BEC10(mutexInfo_p, handle);
    if (req_p == 0 || username_p == 0 || password_p == 0) {
        return -1;
    }
    username_len = func_021BA124(username_p, 0x21);
    password_len = func_021BA124(password_p, 0x21);
    if (username_len <= 0x20 && password_len <= 0x20) {
        func_021BA13C(tmpbuf, 0x41);
        func_021BA100(tmpbuf, username_p, username_len);
        func_021BA100(tmpbuf + username_len, g_021CE53C, 1);
        func_021BA100(tmpbuf + (username_len + 1), password_p, password_len);
        req_p->authLen = func_021BA714(req_p->auth, tmpbuf);
    } else {
        return -1;
    }
    return 0;
}
