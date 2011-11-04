/*************************************************************
 *    
 *  OTBylaw.h
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OT_BYLAW_H__
#define __OT_BYLAW_H__




#include <string>

#include "OTString.h"


class OTIdentifier;

// ------------------------------------------------------------------


// Agent is always either the Owner Nym acting in his own interests,
// or is an employee Nym acting actively in a role on behalf of an Entity formed by contract
// or is a voting group acting passively in a role on behalf of an Entity formed by contract

// QUESTION: What about having an agent being one Nym representing another?
// NO: because then he needs a ROLE in order to act as agent. In which case, the other
// nym should just create an entity he controls, and make the first nym an agent for that entity.

class OTPseudonym;
class OTParty;

class OTAgent 
{
private:
    bool m_bNymRepresentsSelf; // Whether this agent represents himself (a nym) or whether he represents an entity of some sort.
    bool m_bIsAnIndividual; // Whether this agent is a voting group or Nym (whether Nym acting for himself or for some entity.)
    
	// If agent is active (has a nym), here is the sometimes-available pointer to said Agent Nym. 
    OTPseudonym *	m_pNym; // this pointer is not owned by this object, and is here for convenience only.
	// someday may add a "role" pointer here.
	
	OTParty *		m_pForParty; // The agent probably has a pointer to the party it acts on behalf of.
	
	/*
	 <Agent type=“group”// could be “nym”, or “role”, or “group”. 
			Nym_id=“” // In case of “nym”, this is the Nym’s ID. If “role”, this is NymID of employee in role.
			Role_id=“” // In case of “role”, this is the Role’s ID.
			Entity_id=“this” // same as OwnerID if ever used. Should remove.
			Group_Name=“class_A” // “class A shareholders” are the voting group that controls this agent. 	 
	 */
	
	OTString m_strName; // agent name (accessible within script language.)
	
	// info about agent.
	//
	OTString m_strNymID;		// If agent is a Nym, then this is the NymID of that Nym (whether that Nym is owner or not.)
								// If agent is a group (IsAGroup()) then this will be blank. This is different than the
								// Nym stored in OTParty, which if present ALWAYS refers to the OWNER Nym (Though this Nym
								// MAY ALSO be the owner, that fact is purely incidental here AND this NymID could be blank.)
	OTString m_strRoleID;		// If agent is Nym working in a role on behalf of an entity, then this is its RoleID in Entity.
	OTString m_strGroupName;	// If agent is a voting group in an Entity, this is group's Name (inside Entity.)
	
    // ------------------------------------------------
	
public:
	OTAgent();
	OTAgent(const std::string str_agent_name, OTPseudonym & theNym, bNymRepresentsSelf=true, 
	/*IF false, then: ENTITY and ROLE parameters go here.*/);
	//
	// Someday another constructor here like the above, for
	// instantiating with an Entity/Group instead of with a Nym.	
	
	OTAgent(bool bNymRepresentsSelf, bool bIsAnIndividual, 
			const OTString& strName, 
			const OTString& strNymID, 
			const OTString& strRoleID, 
			const OTString& strGroupName);
	
	virtual ~OTAgent();
	
	void Serialize(OTString & strAppend);

    // ---------------------------------

    void SetParty(OTParty & theOwnerParty); // This happens when the agent is added to the party.
	
	// ---------------------------------
    // Only one of these can be true:
    // (I wrestle with making these 2 calls private, since technically it should be irrelevant to the external.)
    //
    bool DoesRepresentHimself() const; // If the agent is a Nym acting for himself, this will be true. Otherwise, if agent is a Nym acting in a role for an entity, or if agent is a voting group acting for the entity to which it belongs, either way, this will be false.
	// ** OR **
    bool DoesRepresentAnEntity() const; // Whether the agent is a voting group acting for an entity, or is a Nym acting in a Role for an entity, this will be true either way. (Otherwise, if agent is a Nym acting for himself, then this will be false.)
	
	// --------------------
	// Only one of these can be true:
    // - Agent is either a Nym acting for himself or some entity, 
    // - or agent is a group acting for some entity.
    
	bool IsAnIndividual() const;	// Agent is an individual Nym. (Meaning either he IS ALSO the party and thus represents himself, OR he is an agent for an entity who is the party, and he's acting in a role for that entity.) If agent were a group, this would be false.
	// ** OR **
    bool IsAGroup() const;			// OR: Agent is a voting group, which cannot take proactive or instant action, but only passive and delayed. Entity-ONLY. (A voting group cannot decide on behalf of individual, but only on behalf of the entity it belongs to.)
    
    // ---------------------
    
    // FYI: A Nym cannot act as agent for another Nym.
    // Nor can a Group act as agent for a Nym.
    // 
    // If you want those things, then the owner Nym should form an Entity, and
    // then groups and nyms can act as agents for that entity. You cannot have
    // an agent without an entity formed by contract, since you otherwise have no agency agreement.
    
	// ----------------------
	// For when the agent is an individual:
	//
	bool GetNymID(OTIdentifier& theOutput) const;		// If IsIndividual(), then this is his own personal NymID, (whether he DoesRepresentHimself() or DoesRepresentAnEntity() -- either way). Otherwise if IsGroup(), this returns false.
    
	bool GetRoleID(OTIdentifier& theOutput) const;		// IF IsIndividual() AND DoesRepresentAnEntity(), then this is his RoleID within that Entity. Otherwise, if IsGroup() or DoesRepresentHimself(), then this returns false.
	
    // --------------------------------------
    // Notice if the agent is a voting group, then it has no signer. (Instead it will have an election.)
    // That is why certain agents are unacceptable in certain scripts.
    // There is an "active" agent who has a signerID, but there is also a "passive" agent who only has
    // a group name, and acts based on notifications and replies in the long-term, versus being immediately
    // able to act as part of the operation of a script.
    // Basically if !IsIndividual(), then GetSignerID() will fail and thus anything needing it as part of the
    // script would also therefore be impossible.
    //
    bool GetSignerID(OTIdentifier& theOutput) const; // If IsIndividual() and DoesRepresentAnEntity() then this returns GetRoleID().
	// else if Individual() and DoesRepresentHimself() then this returns GetNymID().
	// else (if IsGroup()) then return false;
	
    // --------------------------------------------------
    // For when the agent DoesRepresentAnEntity():
    //
    // Whether this agent IsGroup() (meaning he is a voting group that DoesRepresentAnEntity()),
    // OR whether this agent is an individual acting in a role for an entity (IsIndividual() && DoesRepresentAnEntity())
    // ...EITHER WAY, the agent DoesRepresentAnEntity(), and this function returns the ID of that Entity.
    //
    // Otherwise, if the agent DoesRepresentHimself(), then this returns false.
    // I'm debating making this function private along with DoesRepresentHimself / DoesRepresentAnEntity().
    //
	bool GetEntityID(OTIdentifier& theOutput) const; // IF represents an entity, this is its ID. Else fail.
    
	const OTString & GetName() { return m_strName; } // agent's name as used in a script.
    // ------------------------------------------    
	// For when the agent is a voting group:
    //
	bool GetGroupName(OTString & strGroupName); // The GroupName group will be found in the EntityID entity.
	//
    // If !IsGroup() aka IsIndividual(), then this will return false.
    //
	// --------------------
	
	//    bool DoesRepresentHimself(); 
	//    bool DoesRepresentAnEntity();     
	//
	//    bool IsIndividual();	
	//    bool IsGroup();	
    
    // PARTY is either a NYM or an ENTITY. This returns ID for that Nym or Entity.
    //
    // If DoesRepresentHimself() then return GetNymID()
    // else (thus DoesRepresentAnEntity()) so return GetEntityID()
    //
    bool GetPartyID(OTIdentifier& theOutput) const;
	
    // IDEA: Put a Nym in the Nyms folder for each entity. While it may
    // not have a public key in the pubkey folder, or embedded within it,
    // it can still have information about the entity or role related to it,
    // which becomes accessible when that Nym is loaded based on the Entity ID.
    // This also makes sure that Nyms and Entities don't ever share IDs, so the
    // IDs become more and more interchangeable.
};


typedef std::map<std::string, OTAgent *> mapOfAgents;


// ------------------------------------------------------------
//
// Each part has a list of accounts. Just as the agent, depending on context, MAY
// have an unowned-but-useful pointer to its active Nym, similarly a partyaccount
// MAY have an unowned-but-useful point to its actual Account.
//
// (Normally, an OTPartyAccount is loaded with the party, as part of an OTScriptable-
// derived object, and it doesn't actually load a copy of the actual Nyms and Accounts
// at that time, it just stores their IDs. But times may also come when the actual pointer
// is passed in for use by the Parties, who are not otherwise expected to do anything
// with it, or to clean it up or rely on it for their normal data storage.)
//


class OTAccount;

// Represents an account (to a party.) This is because ACTUALLY loading the REAL account is a pain in the ass,
// and we just want to store its ID, etc.  This way, the party can OWN this information about this list of
// accounts, and store it, load it, destroy it, etc, often without involving the actual account file at all.
//
// (Even if a this isn't currently doing anything with any of the party's accounts, the contract still
// has to have a LIST of them, so it knows what to do in those cases when it DOES need to do something.)
//
// For example, this is where we store the CLOSING TRANSACTION # for that account (for this agreement.)
// That number can't be found in the account itself, but all smart contracts involving asset accounts must
// provide a closing number for each asset account.

class OTPartyAccount 
{
	OTParty *	m_pForParty; // When being added to a party, this pointer will be set.

	// -------------------------

	// NOTE: each party needs to have a list of partyaccounts, AND each account on that list needs to have a CLOSING #!!! Ahh...
	OTAccount * m_pAccount; 
	long		m_lClosingTransNo; // Any account that is party to an agreement, must have a closing transaction # for finalReceipt.

	// -------------------------
	// account name (inside the script language, "gold_acct_A" could be used to reference this acct.)
	//
	OTString	m_strName;			// Name of the account (for use in scripts.)
	OTString	m_strAcctID;		// The Account ID itself.

	// -------------------------

	// Entity, role, and Nym information are not stored here.
	// Entity is already known on the party who owns this account (and I should have a ptr to him.)
	// Role is already known on the agent who is presumably on the party's list of agents.
	// Nym is known on the party (for owner) and on the agent.
	
	// "GetOwnerID()" for a partyaccount (if it were to store NymID, EntityID, and a bool to choose
	// between them) should be logically the same as m_pOwnerParty->GetPartyID().
	//
	
public:
	OTPartyAccount();
	OTPartyAccount(const std::string str_account_name, const OTAccount & theAccount, long lClosingTransNo);
	OTPartyAccount(const OTString & strName, const OTString & strAcctID, long lClosingTransNo);
	
	virtual ~OTPartyAccount();
	
	void Serialize(OTString & strAppend);

	// --------
	
	void SetParty(OTParty & theOwnerParty); // This happens when the partyaccount is added to the party. (so I have a ptr back)

	const OTString & GetName() { return m_strName; } // account's name as used in a script.
	
	long GetClosingTransNo() { return m_lClosingTransNo; }
};



typedef std::map<std::string, OTPartyAccount *> mapOfPartyAccounts;



// ------------------------------------------------------------


// Party is always either an Owner Nym, or an Owner Entity formed by Contract.
//
// Either way, the agents are there to represent the interests of the parties.
// 
// This is meant in the sense of "actually" since the agent is not just a trusted
// friend of the party, but is either the party himself (if party is a Nym), OR is
// a voting group or employee that belongs to the party. (If party is an entity.)
// Either way, the point is that in this context, the agent is ACTUALLY authorized
// by the party by virtue of its existence, versus being a "separate but authorized"
// party in the legal sense. No need exists to "grant" the authority since the
// authority is already INHERENT.
//
// A party may also have multiple agents.
//
class OTParty 
{
    std::string * m_pstr_party_name;
    
    bool m_bPartyIsNym;  // true, is "nym". false, is "entity".
    
	std::string	m_str_owner_id;  // Nym ID or Entity ID.
		
	mapOfAgents			m_mapAgents; // These are owned.
	mapOfPartyAccounts	m_mapPartyAccounts; // These are owned. Each contains a Closing Transaction#.
	
	long	m_lOpeningTransNo; // Each party (to a smart contract anyway) must provide an opening transaction #.
		
	OTString        m_strMySignedCopy; // One party confirms it and sends it over. Then another confirms it, 
	// which adds his own transaction numbers and signs it. This, unfortunately, invalidates the original version,
	// (since the digital signature ceases to verify, once you change the contents.) So... we store a copy of each
	// signed agreement INSIDE each party. The server can do the hard work of comparing them all, though such will
	// probably occur through a comparison function I'll have to add right here in this class.
	
public:
	OTParty();
	OTParty(const char * szName, bool bIsOwnerNym, const char * szOwnerID);
	OTParty(const std::string str_PartyName, OTPseudonym & theNym, OTAccount * pAccount=NULL);
	
	virtual ~OTParty();
	
//    OTParty(const OTParty & rhs);
//    OTParty& operator= (const OTParty & rhs);
	
	void Serialize(OTString & strAppend);
	
	// ---------------------
	
	void SetMySignedCopy(const OTString & strMyCopy) { m_strMySignedCopy = strMyCopy; }
    const OTString & GetMySignedCopy() { return m_strMySignedCopy; }

	// ---------------------
	
	long GetOpeningTransNo() const { return m_lOpeningTransNo; }
	void SetOpeningTransNo(const long & theNumber) { m_lOpeningTransNo = theNumber; }

	// There is one of these for each asset account on the party.
	// You need the acct name to look it up.
	//
	long GetClosingTransNo(const std::string str_for_acct_name) const;

    // -------------------------------------------------
    // as used "IN THE SCRIPT."
    //
    std::string GetPartyName(bool * pBoolSuccess=NULL) const; // "sales_director", "marketer", etc
    void SetPartyName(const std::string & str_party_name_input);
    
	// --------------------
	// ACTUAL PARTY OWNER (Only ONE of these can be true...)
    // Debating whether these two functions should be private. (Should it matter to outsider?)
    //
	bool IsNym() const; // If the party is a Nym. (The party is the actual owner/beneficiary.)
	bool IsEntity() const; // If the party is an Entity. (Either way, the AGENT carries out all wishes.)
	
	// ------------------------------
	// ACTUAL PARTY OWNER
    //
    std::string GetNymID(bool * pBoolSuccess=NULL) const; // If the party is a Nym, this is the Nym's ID. Otherwise this is false.
    std::string GetEntityID(bool * pBoolSuccess=NULL) const; // If party is an entity, this is the entity's ID. Otherwise false.
	// ----------------------------
    
	// If party is a Nym, this is the NymID. Else return EntityID().
    std::string GetPartyID(bool * pBoolSuccess=NULL) const; 
	
    // --------------------------------------------------
    // Some agents are passive (voting groups) and cannot behave actively, and so cannot do
    // certain things that only Nyms can do. But they can still act as an agent in CERTAIN
    // respects, so they are still allowed to do so. However, likely many functions will
    // require that HasActiveAgent() be true for a party to do various actions. Attempts to
    // do those actions otherwise will fail.
    // It's almost a separate kind of party but not worthy of a separate class.
    //
    bool HasActiveAgent() const;

	int  GetAgentCount() const { return m_mapAgents.size(); }
    
	bool AddAgent(OTAgent& theAgent);
	// ----------------------------------------
	
	bool AddAccount(OTPartyAccount& thePartyAcct);
	bool AddAccount(const OTString& strName, const OTString & strAcctID, const long lClosingTransNo);
	bool AddAccount(const char * szAcctName, OTAccount& theAccount, const long lClosingTransNo);
	
	int GetAccountCount() const { return m_mapPartyAccounts.size(); }
		
    // ------------- OPERATIONS -------------
	
	// Below this point, have all the actions that a party might do.
    //
    // (The party will internally call the appropriate agent according to its own rules.
    // the script should not care how the party chooses its agents. At the most, the script
    // only cares that the party has an active agent, but does not actually speak directly
    // to said agent.)
		
    
};


typedef std::map<std::string, OTParty *> mapOfParties;


// ------------------------------------------------------------

class OTBylaw;
// ------------------------------------------------------------




class OTClause
{
	OTString	m_strName;		// Name of this Clause.
	OTString	m_strCode;	// script code.
	
	OTBylaw	*	m_pBylaw; // the Bylaw that this clause belongs to.
	
public:
	void SetBylaw(OTBylaw& theBylaw) { m_pBylaw = &theBylaw; }
	
	OTClause();
	OTClause(const char * szName, const char * szCode);
	virtual ~OTClause();
	
	void Serialize(OTString & strAppend);	
};

typedef std::map<std::string, OTClause *> mapOfClauses;



// ------------------------------------------------------------


// A section of law, including its own clauses (scripts). A bylaw is kind of
// like an OT script "program", so it makes sense to be able to collect them,
// and to have them as discrete "packages".
//
class OTBylaw
{
	OTString		m_strName;		// Name of this Bylaw.
	OTString		m_strLanguage;	// Language that the scripts are written in, for this bylaw.

	mapOfClauses	m_mapClauses;
	
	
	// TODO:  CONSTANTS / VARIABLES... 
	
public:
	OTString & GetName() { return m_strName; }
	
	const char * GetLanguage() const;
	
	bool AddClause(OTClause& theClause);
	bool AddClause(const char * szName, const char * szCode);
	
	OTBylaw();
	OTBylaw(const char * szName, const char * szLanguage);

	virtual ~OTBylaw();
	
	void Serialize(OTString & strAppend);
};




typedef std::map<std::string, OTBylaw *> mapOfBylaws;
























#endif // __OT_BYLAW_H__



