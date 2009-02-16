#ifndef NETWORK_MODEL_ANALYTICAL_H
#define NETWORK_MODEL_ANALYTICAL_H

#include "network.h"

class NetworkModelAnalytical : public NetworkModel
{
   public:
      NetworkModelAnalytical(Network *net);
      ~NetworkModelAnalytical();

      void routePacket(const NetPacket &pkt,
                       std::vector<Hop> &nextHops);

      void outputSummary(std::ostream &out);

   private:
      UInt64 computeLatency(const NetPacket &);
      void updateUtilization();
      static void receiveMCPUpdate(void *, NetPacket);

      UInt64 _bytesSent;
      UInt32 _bytesRecv;

      UInt64 _cyclesProc;
      UInt64 _cyclesLatency;
      UInt64 _cyclesContention;
      UInt64 _procCost;

      double _globalUtilization;
      UInt64 _localUtilizationLastUpdate;
      UInt64 _localUtilizationFlitsSent;
      UInt64 _updateInterval;
};

#endif // NETWORK_MODEL_ANALYTICAL_H