#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT tictactoe : public contract {
	public:
	  using contract::contract;

	  ACTION welcome(name host, name challenger) {
		  require_auth( get_self() );
		  print("Welcome, challengers %s and %s! ", host, challenger );
	  }
};


