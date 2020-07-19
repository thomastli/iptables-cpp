#include "iptables/Rule.hpp"

using namespace iptables;

bool Rule::hasTarget() {
  bool result = false;
  if (target != Target::NONE) {
    result = true;
  }
  return result;
}

bool Rule::hasProtocol() {
  bool result = false;
  if (protocol != Protocol::NONE) {
    result = true;
  }
  return result;
}

bool Rule::hasOptValue() {
  bool result = false;
  result = !opt.empty();
  return result;
}

bool Rule::hasInValue() {
  bool result = false;
  result = !in.empty();
  return result;
}

bool Rule::hasOutValue() {
  bool result = false;
  result = !out.empty();
  return result;
}

bool Rule::hasSource() {
  bool result = false;
  result = source.hasHostName() || source.hasIpAddress();
  return result;
}

bool Rule::hasDestination() {
  bool result = false;
  result = destination.hasHostName() || destination.hasIpAddress();
  return result;
}

Protocol Rule::getProtocol() {
  return this->protocol;
}

Target Rule::getTarget() {
  return this->target;
}

std::string Rule::getOptValue() {
  return this->opt;
}

std::string Rule::getInValue() {
  return this->in;
}

std::string Rule::getOutValue() {
  return this->out;
}

Address Rule::getSourceAddress() {
  return this->source;
}

Address Rule::getDestinationAddress() {
  return this->destination;
}

void Rule::setTarget(Target& target) {
  this->target = target;
}

void Rule::setProtocol(Protocol& protocol) {
  this->protocol = protocol;
}

void Rule::setOptValue(std::string& opt) {
  this->opt = opt;
}

void Rule::setInValue(std::string& in) {
  this->in = in;
}

void Rule::setOutValue(std::string& out) {
  this->out = out;
}

void Rule::setSourceAddress(Address& source) {
  this->source = source;
}

void Rule::setDestinationAddress(Address& destination) {
  this->destination = destination;
}

std::string Rule::parseProtocolToString() {
  std::string protocolValue;

  switch (protocol) {
    case Protocol::TCP:
      protocolValue = "TCP";
      break;
    case Protocol::UDP:
      protocolValue = "UDP";
      break;
    case Protocol::ICMP:
      protocolValue = "ICMP";
      break;
    case Protocol::ALL:
      protocolValue = "ALL";
      break;
  }

  return protocolValue;
}

std::string Rule::parseTargetToString() {
  std::string targetValue;

  switch (target) {
    case Target::ACCEPT:
      targetValue = "ACCEPT";
      break;
    case Target::DECLINE:
      targetValue = "DECLINE";
      break;
  }

  return targetValue;
}
