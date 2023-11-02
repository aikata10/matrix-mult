#include "matrix_mult_ckks.h"

MatrixMultCKKS::MatrixMultCKKS(std::string ccLocation, std::string pubKeyLocation, std::string multKeyLocation,
                               std::string rotKeyLocation,
                               std::string matrixALocation,
                               std::string matrixBLocation,
                               std::string outputLocation) : m_PubKeyLocation(pubKeyLocation),
                                                             m_MultKeyLocation(multKeyLocation),
                                                             m_RotKeyLocation(rotKeyLocation),
                                                             m_CCLocation(ccLocation),
                                                             m_MatrixALocation(matrixALocation),
                                                             m_MatrixBLocation(matrixBLocation),
                                                             m_OutputLocation(outputLocation)
{

    initCC();
};

void MatrixMultCKKS::initCC()
{
    if (!Serial::DeserializeFromFile(m_CCLocation, m_cc, SerType::BINARY))
    {
        std::cerr << "Could not deserialize cryptocontext file" << std::endl;
        std::exit(1);
    }

    if (!Serial::DeserializeFromFile(m_PubKeyLocation, m_PublicKey, SerType::BINARY))
    {
        std::cerr << "Could not deserialize public key file" << std::endl;
        std::exit(1);
    }

    std::ifstream multKeyIStream(m_MultKeyLocation, std::ios::in | std::ios::binary);
    if (!multKeyIStream.is_open())
    {
        std::exit(1);
    }
    if (!m_cc->DeserializeEvalMultKey(multKeyIStream, SerType::BINARY))
    {
        std::cerr << "Could not deserialize rot key file" << std::endl;
        std::exit(1);
    }

    std::ifstream rotKeyIStream(m_RotKeyLocation, std::ios::in | std::ios::binary);
    if (!rotKeyIStream.is_open())
    {
        std::exit(1);
    }

    if (!m_cc->DeserializeEvalAutomorphismKey(rotKeyIStream, SerType::BINARY))
    {
        std::cerr << "Could not deserialize eval rot key file" << std::endl;
        std::exit(1);
    }

    if (!Serial::DeserializeFromFile(m_MatrixALocation, m_MatrixAC, SerType::BINARY))
    {
        std::cerr << "Could not deserialize Matrix A cipher" << std::endl;
        std::exit(1);
    }

    if (!Serial::DeserializeFromFile(m_MatrixBLocation, m_MatrixBC, SerType::BINARY))
    {
        std::cerr << "Could not deserialize Matrix B cipher" << std::endl;
        std::exit(1);
    }
}

void MatrixMultCKKS::eval()
{
    // You should implement this function
}

void MatrixMultCKKS::deserializeOutput()
{
    if (!Serial::SerializeToFile(m_OutputLocation, m_OutputC, SerType::BINARY))
    {
        std::cerr << " Error writing ciphertext 1" << std::endl;
    }
}