#include "hiloapache.h"
#include "Juego.h"
#include "niveles.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace  ::Servidor;

HiloApache::HiloApache(Niveles *nivel,QTextEdit *textEdit)
{
    this->nivel = nivel;
    this->textEdit = textEdit;
}

class JuegoHandler : virtual public JuegoIf {
 public:
    Niveles *nivel;
    QTextEdit *textEdit;
  JuegoHandler(Niveles *nivel,QTextEdit *textEdit) {
    this->nivel = nivel;
    this->textEdit = textEdit;
  }

  bool atacar(const int32_t x, const int32_t y) {
      //textEdit->setText("201503823@Gianni:~ Atacando Nodo Servicio");
      return nivel->atacar(x,y);

    //printf("atacar\n");
  }

};

void HiloApache::run()
{
    //while(true)
    //{
        int port = 9090;
        ::apache::thrift::stdcxx::shared_ptr<JuegoHandler> handler(new JuegoHandler(nivel,textEdit));
        ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new JuegoProcessor(handler));
        ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
        ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
        ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

        TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
        server.serve();
    //}
}

/*int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<JuegoHandler> handler(new JuegoHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new JuegoProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}*/
