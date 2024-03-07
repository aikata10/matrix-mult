#include "openfhe.h"

#include <cmath>
// header files needed for serialization
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "key/key-ser.h"
#include "scheme/ckksrns/ckksrns-ser.h"

using namespace lbcrypto;

class MatrixMultCKKS {
    CryptoContext<DCRTPoly> m_cc;
    PublicKey<DCRTPoly> m_PublicKey;
    Ciphertext<DCRTPoly> m_MatrixAC;
    Ciphertext<DCRTPoly> m_MatrixBC;
    Ciphertext<DCRTPoly> m_OutputC;
    std::string m_PubKeyLocation;
    std::string m_MultKeyLocation;
    std::string m_RotKeyLocation;
    std::string m_CCLocation;
    std::string m_MatrixALocation;
    std::string m_MatrixBLocation;
    std::string m_OutputLocation;

public:
    MatrixMultCKKS(std::string ccLocation, std::string pubKeyLocation, std::string multKeyLocation,
                std::string rotKeyLocation,
                std::string matrixALocation,
                std::string matrixBLocation,
                std::string outputLocation);

    void initCC();

    void eval();

    void deserializeOutput();

};
