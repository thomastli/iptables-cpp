#include "iptables/Rule.hpp"

using namespace iptables;

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

IpAddress Rule::getSourceAddress() {
  return this->source;
}

IpAddress Rule::getDestinationAddress() {
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

void Rule::setSourceAddress(IpAddress& source) {
  this->source = source;
}

void Rule::setDestinationAddress(IpAddress& destination) {
  this->destination = destination;
}