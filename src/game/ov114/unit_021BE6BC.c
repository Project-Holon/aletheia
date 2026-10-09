/*
 * file:     unit_021BE6BC.c
 * unit:     yes
 * function: func_021BE6BC, func_021BE6EC, func_021BE748, func_021BE79C, func_021BE7FC, func_021BE838, func_021BE880, func_021BE8B8, func_021BE8E8, func_021BE9C8, func_021BE9F8
 * address:  0x021BE6BC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEC10  0x021BEC10  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 *   func_021BEF3C 0x021BEF3C arm ov114
 *   func_021BAC38 0x021BAC38 arm ov114
 *   func_021BAC58 0x021BAC58 arm ov114
 *   func_021BBCF0  0x021BBCF0  arm  ov114
 *   func_021BEC2C  0x021BEC2C  arm  ov114
 *   func_021BBDFC 0x021BBDFC arm ov114
 *   func_021BA124 0x021BA124 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 *   func_021BA100 0x021BA100 arm ov114
 *   func_021BA714 0x021BA714 arm ov114
 *   g_021CE53C 0x021CE53C data
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
} Req_021BE6BC;

typedef struct {
    int f0;
    int f4;
    char pad[8];
    int f10;
    char pad2[0x20];
    void *f34;
    char pad3[0x214];
    void *f24c;
    unsigned long f250;
} Req_021BE79C;

typedef struct {
    char pad[0x4c];
    char auth[0x5c];
    int authLen;
} Req;

extern u8 *func_021BEF08(void);
extern void *func_021BEF58();
extern int func_021BEC10(int, int);
extern void *func_021BEF3C(void);
extern int func_021BAC38(u32 *p, int a, int b, int c);
extern int func_021BAC58(void *req_p, void *bgnEndInfo_p, char *label_p, char *value_p);
extern int func_021BEC2C(int, int);
extern int func_021BBCF0(u8 *, int, int);
extern int func_021BBDFC(void *bgnEndInfo_p, void *res_p, char **value_pp);
extern int func_021BA124(char *s, int max);
extern void func_021BA13C(int a, int b);
extern void func_021BA100(void *dst_p, void *src_p, int size);
extern int func_021BA714(char *dst_p, const char *src_p);
void func_021BE6BC(int a, int b, int c);
int func_021BE6EC(Req_021BE6BC *req_p, char *label_p, char *value_p);
int func_021BE748(void *handle, char *label_p, char *value_p);
int func_021BE79C(void *handle, void *value_p, unsigned long length);
int func_021BE7FC(int a, int b, int c);
int func_021BE838(void *handle, char **value_pp);
int func_021BE880(int a);
int func_021BE8B8(int a, int v);
int func_021BE8E8(void *handle, char *username_p, char *password_p);
int func_021BE9C8(int a, int b, int c);
int func_021BE9F8(u8 *p, int a, int b);
extern char g_021CE53C[];







void func_021BE6BC(int a, int b, int c)
{
    func_021BE6EC((Req_021BE6BC *)(func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a)), (char *)b, (char *)c);
}







int func_021BE6EC(Req_021BE6BC *req_p, char *label_p, char *value_p)
{
    void *bgnEndInfo_p;

    func_021BEF08();
    bgnEndInfo_p = func_021BEF3C();
    if (req_p == 0) {
        return -1;
    }
    if (req_p->f4 != 0) {
        return -1;
    }
    return -(func_021BAC38((u32 *)req_p, (int)bgnEndInfo_p, (int)label_p, (int)value_p) == 0);
}






int func_021BE748(void *handle, char *label_p, char *value_p)
{
    void *sysInfo_p = func_021BEF08();
    void *bgnEndInfo_p = func_021BEF3C();
    void *mutexInfo_p = func_021BEF58((int)sysInfo_p);
    void *req_p = (void *)func_021BEC10((int)mutexInfo_p, (int)handle);
    return -(func_021BAC58(req_p, bgnEndInfo_p, label_p, value_p) == 0);
}





int func_021BE79C(void *handle, void *value_p, unsigned long length)
{
    Req_021BE79C *req_p;
    void *mutexInfo_p;

    func_021BEF08();
    mutexInfo_p = func_021BEF58();
    req_p = (Req_021BE79C *)func_021BEC10((int)mutexInfo_p, (int)handle);
    if (req_p == 0) {
        return -1;
    }
    if (req_p->f4 != 0) {
        return -1;
    }
    if (req_p->f34 != 0) {
        return -1;
    }
    req_p->f10 = 1;
    req_p->f24c = value_p;
    req_p->f250 = length;
    return 0;
}





/*
 * Keyed lookup then dispatch; -1 when the key is unknown.
 */
int func_021BE7FC(int a, int b, int c)
{
    u8 *p = (u8 *)func_021BEC2C((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    return func_021BBCF0(p, b, c);
}






int func_021BE838(void *handle, char **value_pp)
{
    void *sysInfo_p = func_021BEF08();
    void *bgnEndInfo_p = func_021BEF3C();
    void *mutexInfo_p = func_021BEF58((int)sysInfo_p);
    void *res_p = (void *)func_021BEC2C((int)mutexInfo_p, (int)handle);
    if (res_p == 0) {
        return -1;
    }
    return func_021BBDFC(bgnEndInfo_p, res_p, value_pp);
}






/*
 * Keyed field read: -1 unknown key, -1 when unset, else the +0x18 word.
 */
int func_021BE880(int a)
{
    u8 *p = (u8 *)func_021BEC2C((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    if (*(u32 *)(p + 0x14) != 0)
        return *(u32 *)(p + 0x18);
    return -1;
}






int func_021BE8B8(int a, int v)
{
    u8 *p = (u8 *)func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a);
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xd0) = v;
    return 0;
}



/*
 * sdk:      NHTTP_SetBasicAuthorization (libnhttp.TWL.HYB.a(d_nhttp.o))
 */
int func_021BE8E8(void *handle, char *username_p, char *password_p)
{
    char tmpbuf[65];
    int password_len;
    int username_len;
    Req *req_p;
    void *mutexInfo_p;

    func_021BEF08();
    mutexInfo_p = func_021BEF58();
    req_p = (Req *)func_021BEC10((int)mutexInfo_p, (int)handle);
    if (req_p == 0 || username_p == 0 || password_p == 0) {
        return -1;
    }
    username_len = func_021BA124(username_p, 0x21);
    password_len = func_021BA124(password_p, 0x21);
    if (username_len <= 0x20 && password_len <= 0x20) {
        func_021BA13C((int)tmpbuf, 0x41);
        func_021BA100(tmpbuf, username_p, username_len);
        func_021BA100(tmpbuf + username_len, g_021CE53C, 1);
        func_021BA100(tmpbuf + (username_len + 1), password_p, password_len);
        req_p->authLen = func_021BA714(req_p->auth, tmpbuf);
    } else {
        return -1;
    }
    return 0;
}



int func_021BE9C8(int a, int b, int c)
{
    return func_021BE9F8((u8 *)func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a), b, c);
}



int func_021BE9F8(u8 *p, int a, int b)
{
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xc8) = 0;
    *(u32 *)(p + 0xdc) = 0;
    *(u32 *)(p + 0xc0) = a;
    *(u32 *)(p + 0xc4) = b;
    return 0;
}
