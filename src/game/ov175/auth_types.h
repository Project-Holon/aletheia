/*
 * Types of the GameSpy web service login (libdwcgswebservices, authservice.c)
 * and of the GameSpy MD5 and big-integer helpers it shares with libdwcgssc.
 *
 * A login (wsLoginRemoteAuth) returns a signed certificate and the matching
 * private data.  The stats library (sc_types.h) passes both on with every
 * report request.
 */
#ifndef AUTH_TYPES_H
#define AUTH_TYPES_H

/* Result of a login (WSLoginResponse.mLoginResult); 1 to 7 are server codes. */
typedef enum WSLoginResult {
    WSLoginResult_SUCCESS = 0,
    WSLoginResult_SERVER_ERROR = 7,
    WSLoginResult_HTTP_ERROR = 100,
    WSLoginResult_PARSE_ERROR = 101,
    WSLoginResult_INVALID_CERTIFICATE = 102,
    WSLoginResult_OUT_OF_MEMORY = 104,
    WSLoginResult_NO_AVAILABILITY_CHECK = 106,
    WSLoginResult_CANCELLED = 107
} WSLoginResult;

struct GHIPost;

/* Callback of a GameSpy SOAP call (gsiExecuteSoap): HTTP result, request and response XML, caller data. */
typedef void (*GSSoapCallback)(int theHttpResult, void *theRequestSoap, void *theResponseSoap, void *theUserData);

/* Function that adds the body parts of the HTTP post of a SOAP call (gsiExecuteSoapCustom). */
typedef void (*GSSoapRequestFunc)(struct GHIPost *thePost, void *theUserData);

/* State of an MD5 computation (GSMD5Init, GSMD5Update, GSMD5Final). */
typedef struct GSMD5_CTX {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
} GSMD5_CTX;

/* Big integer of up to 64 words (RSA modulus and exponent). */
typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt_t;

typedef struct gsCryptRSAKey {
    gsLargeInt_t modulus;
    gsLargeInt_t exponent;
} gsCryptRSAKey;

/* Signed login certificate (0x380 bytes). */
typedef struct GSLoginCertificate {
    int mIsValid;
    unsigned int mLength;
    unsigned int mVersion;
    unsigned int mPartnerCode;
    unsigned int mNamespaceId;
    unsigned int mUserId;
    unsigned int mProfileId;
    unsigned int mExpireTime;
    char mProfileNick[31];
    char mUniqueNick[21];
    char mCdKeyHash[33];
    gsCryptRSAKey mPeerPublicKey;
    unsigned char mSignature[128];
    unsigned char mServerData[128];
} GSLoginCertificate;

/* Private key of a login and its MD5 hash (0x218 bytes). */
typedef struct GSLoginCertificatePrivate {
    gsCryptRSAKey mPeerPrivateKey;
    char mKeyHash[16];
} GSLoginCertificatePrivate;

/* Result of a login, passed to the login callback (0x5a0 bytes). */
typedef struct WSLoginResponse {
    int mLoginResult;
    int mResponseCode;
    GSLoginCertificate mCertificate;
    GSLoginCertificatePrivate mPrivateData;
    void *mUserData;
} WSLoginResponse;

typedef void (*WSLoginCallback)(int theHttpResult, WSLoginResponse *theResponse, void *theUserData);

/* Caller callback and data kept while the login SOAP request runs. */
typedef struct WSIRequestData {
    WSLoginCallback mUserCallback;
    void *mUserData;
} WSIRequestData;

#endif
