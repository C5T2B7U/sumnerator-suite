//
//                     O------------------------O
//                     | SUMNERATOR REV09 SUITE |
//                     O------------------------O
//
// <TECHNICIAN=>     SUMNER, BRIAN
// <SEQUENCE=>       https://github.com/C5T2B7U/sumnerator_suite.git
//




#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <bitset>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::setw;
using std::setfill;
using std::bitset;
using std::toupper;



void encGCAT07(ofstream &encoded, int numEmbryos, string source);
void bootstrap_01(ofstream &make, string automatic);
void bootstrap_02(ofstream &make, int numEmbryos);


int main()
{
	
	
	int numEmbryos, index;
	string makeFile, automatic;



	
	cout << "----------------------\n"
		<< "SUMNERATOR REV09 SUITE\n"
		<< "----------------------\n\n";


	cout << "ENTER FILE NAME TO BUILD>  ";
	getline(cin, makeFile);


	if (makeFile.length() > 4)
	{
		int length = makeFile.length();

		if (
			makeFile[length-4] == '.' &&
			toupper(makeFile[length-3]) == 'C' &&
			toupper(makeFile[length-2]) == 'P' &&
			toupper(makeFile[length-1]) == 'P'
			)
		{
			// DO NOTHING
		}
		else makeFile += ".cpp";

	}
	else makeFile += ".cpp";


	ofstream make(makeFile.c_str());




	cout << "\nFOR AUTOMATIC MANIFESTATION ENTER 'Y' NOW>  ";
	getline(cin, automatic);

	if (automatic == "Y" || automatic == "y")
		automatic = "// ";
	else
		automatic = "";



	cout << "\nENTER NUMBER OF EMBRYOS>  ";
	cin >> numEmbryos;
	cin.ignore();

	string manifestation[numEmbryos];



	bootstrap_01(make, automatic);
	bootstrap_02(make, numEmbryos);
	



	for (index = 0; index < numEmbryos; index++)
	{
		string id, helix;
		ifstream testFile;


		testFile.open("");


		cout << "\nENTER EMBRYO " << setw(2) << setfill('0') << index + 1 << " ID>  ";
		getline(cin, id);


		do
		{
			testFile.close();
			testFile.clear();

			cout << "ENTER EMBRYO " << setw(2) << setfill('0') << index + 1 << " FILE NAME>  ";
			getline(cin, manifestation[index]);

			testFile.open(manifestation[index].c_str());

		} while (!testFile.good());


		testFile.close();


		helix = manifestation[index] + ".EMBRYO";


		make << "NURSERY EMBRYO_" << setw(2) << setfill('0') << index + 1 << " = " << endl
			<< "{" << endl
			<< "	\"" << id << "\", " << endl
			<< "	\"" << helix << "\", " << endl
			<< "	\"" << manifestation[index] << "\", " << endl
			<< "};" << "\n\n\n";
	}

	
	
	make << "void GCAT();" << endl
		<< "void HARVEST_EMBRYO(NURSERY EMBRYO);" << "\n\n\n";



	for (index = 0; index < numEmbryos; index++)
	{
		make << "void MANIFEST_" << setw(2) << setfill('0') << index + 1 
					<< "(){HARVEST_EMBRYO(EMBRYO_" << setw(2) << setfill('0') << index + 1 << ");}" << endl
			<< "void IMPLANT_HELIX_" << setw(2) << setfill('0') << index + 1
					<< "(NURSERY EMBRYO=EMBRYO_" << setw(2) << setfill('0') << index + 1 << ");" << "\n\n\n";
	}


	make << "bool IMPLANT_HELIX()" << endl
		<< "{" << endl

		<< " 	ofstream probe;" << endl
		<< "	probe.open(EMBRYO_01.MANIFESTATION.c_str());" << endl
		<< endl
		<< "	if (probe.fail())" << endl
		<< "	{" << endl
		<< "		probe.close();" << endl
		<< "		return -1;" << endl
		<< "	}" << endl
		<< endl
		<< "	probe.close();" << "\n\n";


	for (index = 0; index < numEmbryos; index++)
	{
		make << "	IMPLANT_HELIX_" << setw(2) << setfill('0') << index + 1 << "(); " << endl;
	}


	make << endl
		<< "	return true;" << endl
		<< "}" << "\n\n\n";



	make << "void MANIFEST()" << endl
		<< "{" << endl;


	for (index = 0; index < numEmbryos; index++)
	{
		make << "	MANIFEST_" << setw(2) << setfill('0') << index + 1 << "();" << endl;
	}


	make << "\n}" << "\n\n\n";
	
	
	make << "void VIEW_NURSERY()" << endl
		<< "{" << endl
		<< "	cout " << "\n\n";
		
		
	for (index = 0; index < numEmbryos; index++)	
	{
		make << " 		<< \"   <EMBRYO_" << setw(2) << setfill('0') << index + 1 
					<< ".ID=>   \" << \"\\\"\" << EMBRYO_" << setw(2) << setfill('0') << index + 1 << ".ID << \"\\\"\" << endl" << endl 
			<< " 		<< \"   <MANIFESTATION=>  \" << \"\\\"\" << EMBRYO_" << setw(2) << setfill('0') << index + 1 
					<< ".MANIFESTATION << \"\\\"\" << \"\\n\\n\"" << "\n\n";
	}

	
	make << "		<< \"\\n\";" << endl
		<< "}\n\n\n\n\n\n\n\n";




	make

		<< "int main()" << endl
		<< "{" << endl
		<< "	cout << \"\\n\\n\\n\"" << endl
		<< "		<< \"                         O--------------------------O\\n\"" << endl
		<< "		<< \"                         | SUMNERATOR REV09 NURSERY |\\n\"" << endl
		<< "		<< \"                         O--------------------------O\\n\\n\\n\"" << endl
		<< "		<< \"      o-----------------------------------------------------------------o\\n\"" << endl
		<< "		<< \"      | THIS NURSERY WILL MANIFEST THE FOLLOWING SOURCE CODE EMBRYO(S): |\\n\" " << endl
		<< "		<< \"      o-----------------------------------------------------------------o\\n\\n\";" << endl
		<< endl
		<< "	VIEW_NURSERY();" << endl
		<< endl
		<< "	cout << \"                          [PRESS ENTER TO CONTINUE] \";" << endl
		<< automatic << "	cin.get();" << endl
		<< endl
		<< endl
		<< "	cout << \"\\n\\n\\n     DO YOU WANT TO MANIFEST THE CODE EMBRYO(S) INTO THE ACTIVE DIRECTORY?\\n\"" << endl
		<< "		<< \"                            [ENTER \\'Y\\' OR \\'N\\' NOW]  \";" << endl
		<< automatic << "		{" << endl
		<< automatic << "			char userWantsManifestation;" << endl
		<< automatic << "			do" << endl
		<< automatic << "			{" << endl
		<< automatic << "				cin >> userWantsManifestation;" << endl
		<< automatic << "				if ((userWantsManifestation == 'N') || (userWantsManifestation == 'n'))" << endl
		<< automatic << "				{" << endl
		<< automatic << "					cout << \"\\n\\n\\n         PLEASE RUN THIS NURSERY AGAIN TO MANIFEST THE CODE EMBRYO(S).\\n\\n\\n\"" << endl
		<< automatic << "						<< \"                           [PRESS ENTER TO EXIT] \";" << endl
		<< automatic << "					cin.ignore();" << endl
		<< automatic << "					cin.get();" << endl
		<< automatic << "					return -1;" << endl
		<< automatic << "				}" << endl
		<< automatic << "			}" << endl
		<< automatic << "			while ((userWantsManifestation != 'Y') && (userWantsManifestation != 'y'));" << endl
		<< automatic << "		}" << endl
		<< endl
		<< endl
		<< "	cout << \"\\n\\n\\n\";" << endl
		<< "	if (!IMPLANT_HELIX())" << endl
		<< "	{" << endl
		<< "		cout << \"\\n\\n\\n                WARNING!!! CANNOT IMPLANT HELIX INTO EMBRYO(S)!\\n\"" << endl
		<< "			<< \"              PLEASE ENABLE WRITE ACCESS TO THE ACTIVE DIRECTORY\\n\"" << endl
		<< "			<< \"          AND RUN THIS NURSERY AGAIN TO MANIFEST THE CODE EMBRYO(S).\\n\\n\"" << endl
		<< "			<< \"                           [PRESS ENTER TO EXIT]  \";" << endl
		<< "		cin.ignore();" << endl
		<< "		cin.get();" << endl
		<< "		return -11;" << endl
		<< "	}" << endl
		<< endl
		<< endl
		<< "	cout << \"\\n\\n\\n            SUCCESSFULLY IMPLANTED HELIX INTO SOURCE CODE EMBRYO(S)\\n\"" << endl
		<< "		<< \"                    [PRESS ENTER TO MANIFEST EMBRYO(S) NOW]\\n\\n\\n\";" << endl
		<< automatic << "	cin.ignore();" << endl
		<< automatic << "	cin.get();" << endl
		<< endl
		<< endl
		<< "	cout << \"           [NOW MANIFESTING THE SOURCE CODE EMBRYO(S). PLEASE WAIT.]\\n\\n\\n\";" << endl
		<< "	MANIFEST();" << endl
		<< "	cout << \"\\n\\n\\n           EMBRYO MANIFESTATION COMPLETE. PLEASE COMPILE AND RUN THE \\n\" " << endl
		<< "		<< \"          SOURCE CODE WHICH HAS MANIFESTED INTO THE ACTIVE DIRECTORY.\\n\\n\\n\"" << endl
		<< "		<< \"                           [PRESS ENTER TO EXIT]\\n\\n\\n\";" << endl
		<< automatic << "	cin.get();" << endl
		<< endl
		<< endl
		<< "	return 420-420;" << endl
		<< "}" << endl
		<< "\n\n\n\n";



	cout << endl;


	for (index = 0; index < numEmbryos; index++)
	{
		make << "\nvoid IMPLANT_HELIX_" << setw(2) << setfill('0') << index + 1
					<< "(NURSERY EMBRYO){ofstream HELIX(EMBRYO.HELIX.c_str());" << endl;
		
		encGCAT07(make, index + 1, manifestation[index]);
	}





	make << "\nvoid GCAT(){cout<<char('('+'*'+'*'+'*'-'+'-'+'+'-'+'-'-'/'-'/'-')');}" << endl

<< "void HARVEST_EMBRYO(NURSERY EMBRYO){int zap='('+'-'-'*'+'-'-'+'-'*'-'+'+')';" << endl
<< "ifstream YOU_ARE_NOT_AUTHORIZED_TO_READ_THIS(EMBRYO.HELIX.c_str());" << endl
<< "ofstream YOU_MUST_IMMEDIATELY_DESIST(EMBRYO.MANIFESTATION.c_str());int bam=" << endl
<< "'('-'+'-'+'-'+'+'/'+')'-'('+'+'+'+'+'+'-'/'-')';bool bang=bam;do{int" << endl
<< "crunch;string zowie;getline(YOU_ARE_NOT_AUTHORIZED_TO_READ_THIS,zowie);" << endl
<< "if(YOU_ARE_NOT_AUTHORIZED_TO_READ_THIS.fail())bang=zap;crunch=bam;int" << endl
<< "klonk='('-'+'+'-'-'*'+')'-'('-'+'+'-'-'*'+')';int whap=klonk+zap;int" << endl
<< "klunk='('-'+'-'*'+')'-'('-'+'+'/'+')'-'('+'/'-'*'+')';int zamm;int zam=" << endl
<< "klonk*klonk+klunk*klunk+klonk*klunk;zamm=zam-klonk;int zammm=" << endl
<< "klonk*klunk*klonk*whap;while(crunch<zowie.length()){int kerplop=bam;" << endl
<< "for(int whack=whap;whack>=bam;whack--){char kapow=zowie[crunch];" << endl
<< "int thwack=klonk+whack+klonk;kerplop+=(kapow==zam?pow(klonk,klunk-whack):" << endl
<< "(kapow==zamm?pow(klonk,klunk-thwack):(kapow==zammm?pow(klonk,klunk-thwack)+" << endl
<< "pow(klonk,klunk-whack):bam)));crunch++;GCAT();}YOU_MUST_IMMEDIATELY_DESIST<<" << endl
<< "char(kerplop);}}while(!bang);YOU_ARE_NOT_AUTHORIZED_TO_READ_THIS.close();" << endl
<< "YOU_MUST_IMMEDIATELY_DESIST.close();}" << endl;




/*

 	CLASSIC BATMAN BATFIGHT WORDS:


    AIEEE!
    AIIEEE!
    ARRGH!
    AWK!
    AWKKKKKK!
    BAM!
    BANG!
    BANG-ETH!
    BIFF!
    BLOOP!
    BLURP!
    BOFF!
    BONK!
    CLANK!
    CLANK-EST!
    CLASH!
    CLUNK!
    CLUNK-ETH!
    CRRAACK!
    CRASH!
    CRRAACK!
    CRUNCH!
    CRUNCH-ETH!
    EEE-YOW!
    FLRBBBBB!
    GLIPP!
    GLURPP!
    KAPOW!
    KAYO!
    KER-SPLOOSH!
    KERPLOP!
    KLONK!
    KLUNK!
    KRUNCH!
    OOOFF!
    OOOOFF!
    OUCH!
    OUCH-ETH!
    OWWW!
    OW-ETH
    PAM!
    PLOP!
    POW!
    POWIE!
    QUNCKKK!
    RAKKK!
    RIP!
    SLOSH!
    SOCK!
    SPLATS!
    SPLATT!
    SPLOOSH!
    SWAAP!
    SWISH!
    SWOOSH!
    THUNK!
    THWACK!
    THWACKE!
    THWAPE!
    THWAPP!
    UGGH!
    URKKK!
    VRONK!
    WHACK!
    WHACK-ETH!
    WHAM-ETH!
    WHAMM!
    WHAMMM!
    WHAP!
    Z-ZWAP!
    ZAM!
    ZAMM!
    ZAMMM!
    ZAP!
    ZAP-ETH
    ZGRUPPP!
    ZLONK!
    ZLOPP!
    ZLOTT!
    ZOK!
    ZOWIE!
    ZWAPP!
    ZZWAP!
    ZZZZWAP!
    ZZZZZWAP!

 */


	make.close();
	
	
	return 420-420;
}





void encGCAT07(ofstream &encoded, int embryoNum, string source)
{
//	string source, object = "";

	const int MAX_PRINTED = 14;

	int index = 1, printed = 0;
	char now;


//	cout << "ENTER SOURCE CODE FILE NAME FOR EMBRYO " << setw(2) << setfill('0') << embryoNum << ">  ";
//	cin >> source;
	ifstream dummy(source.c_str());


	encoded << "HELIX<<\"";


	while (dummy.get(now))
	{
		
		char letter;
		
		{
		
			string binary = bitset<8> (now).to_string();    // to binary
	
			for (int low = 3; low >= 0; low--)
			{
				int high = low + 4;
			
				switch (binary[high])
				{
					case '0':	switch (binary[low])
								{

									case '0':	letter = 'G';
												break;
									case '1':	letter = 'C';
												break;
								}
								break;				
					case '1':	switch (binary[low])
								{
									case '0':	letter = 'A';
												break;
									case '1':	letter = 'T';
												break;
								}
								break;
				}
			
			encoded << letter;	
			}
	
		}

		
		printed++;

		if (printed==MAX_PRINTED)
		{
			encoded << "\\n\";GCAT();\nHELIX<<\"";
			printed = 0;
		}


	}
	encoded << "\";GCAT();HELIX.close();}";


	dummy.close();
}







void bootstrap_01(ofstream &make, string automatic)
{

	string technician, authorization, gestation, sequence;


	make    << "//                                                                  " << endl
			<< "//                 O--------------------------O                     " << endl
			<< "//                 | SUMNERATOR REV09 NURSERY |                     " << endl
			<< "//                 O--------------------------O                     " << endl
			<< "//                                                                  " << endl;


	if (automatic != "")
	{
		make	<< "//                                                                  " << endl
				<< "// <AUTOMATIC MANIFESTATION IS ENABLED>                             " << endl
				<< "//                                                                  " << endl
				<< "//                                                                  " << endl;
	}


	cout << "\nENTER TECHNICIAN>  ";
	getline(cin, technician);
	make << "// <TECHNICIAN=>     " << technician << endl;
	
	
	cout << "ENTER AUTHORIZATION>  ";
	getline(cin, authorization);
	make << "// <AUTHORIZATION=>  " << authorization << endl;
	
	
	cout << "ENTER GESTATION>  ";
	getline(cin, gestation);
	make << "// <GESTATION=>      " << gestation << endl;
	
	
	cout << endl;
	
	
	do
	{
		cout << "ENTER SEQUENCE [PRESS ENTER TO STOP]>  ";
		getline(cin, sequence);
		
		if (sequence != "")
			make << "// <SEQUENCE=>       " << sequence << endl;	
		
	} while (sequence != "");



}






void bootstrap_02(ofstream &make, int numEmbryos)
{
	make << "//                                                                  " << "\n\n\n\n"

		<< "#include <iostream>" << endl
		<< "#include <string>" << endl
		<< "#include <fstream>" << endl
		<< "#include <cmath>" << endl
		<< "using std::cin;" << endl
		<< "using std::cout;" << endl
		<< "using std::endl;" << endl
		<< "using std::ifstream;" << endl
		<< "using std::ofstream;" << endl
		<< "using std::string;" << endl
		<< "using std::pow;" << "\n\n\n"

		<< "const int EMBRYOS = " << numEmbryos << ";" << "\n\n\n"

		<< "struct NURSERY" << endl
		<< "{" << endl
		<< "	string ID;" << endl 
		<< "	string HELIX;" << endl
		<< "	string MANIFESTATION;" << endl
		<< "};" << "\n\n\n";
}
