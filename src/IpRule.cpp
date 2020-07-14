#include "iptables/IpRule.hpp"

using namespace iptables;

unsigned int IpRule::getNumId() {
  return this->num;
}

Protocol IpRule::getProtocol() {
  return this->protocol;
}

Target IpRule::getTarget() {
  return this->target;
}

std::string IpRule::getOptValue() {
  return this->opt;
}

std::string IpRule::getInValue() {
  return this->in;
}

std::string IpRule::getOutValue() {
  return this->out;
}

std::string IpRule::getSourceAddress() {
  return this->source;
}

std::string IpRule::getDestinationAddress() {
  return this->destination;
}

void IpRule::setNumId(unsigned int numId) {
  this->num = numId;
}

void IpRule::setTarget(Target& target) {
  this->target = target;
}

void IpRule::setProtocol(Protocol& protocol) {
  this->protocol = protocol;
}

void IpRule::setOptValue(std::string& opt) {
  this->opt = opt;
}

void IpRule::setInValue(std::string& in) {
  this->in = in;
}

void IpRule::setOutValue(std::string& out) {
  this->out = out;
}

void IpRule::setSourceAddress(std::string& source) {
  this->source = source;
}

void IpRule::setDestinationAddress(std::string& destination) {
  this->destination = destination;
}