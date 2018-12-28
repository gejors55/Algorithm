// Examen junio 2016: Implementacion de un sistema de reproduccion de musica
// APDO B: hay que reducir los costes de deleteSong y play

#include "lista.h"
#include "DiccionarioHash.h"
#include <iostream>
#include <string>
using namespace std;

typedef string Cancion;
typedef string Artista;
class SongInfo {
public:
		Artista artist;
		int duration;
		// APDO B: sustituimos los booleanos por iteradores que apuntan al elemento de las listas
		// de reproducción y reproducidas donde están las canciones de las que el correspondiente 
		// objeto SongInfo es información
		//bool inPlaylist;
		//bool played;
		Lista<Cancion>::Iterator itPlaylist;
		Lista<Cancion>::Iterator itPlayed;
		// OJO: los constructores de los iteradores son privados
		// Definimos el siguiente constructor al que le pasaremos los end() de las listas correspondientes
		// cuando creemos un objeto en addSong
		SongInfo(const Lista<Cancion>::Iterator& itplaylist, const Lista<Cancion>::Iterator& itplayedlist) :
			itPlaylist(itplaylist), itPlayed(itplayedlist) {}
	};
// clases excepcion para iPud
class ECancionExistente{};
class ECancionNoExistente{};
// clase iPud
class iPud {	
	Lista<Cancion> playlist;
    Lista<Cancion> played;
	int duration;
	DiccionarioHash<Cancion,SongInfo> songs;
public:
	iPud() : duration(0), playlist(Lista<Cancion>()), played(Lista<Cancion>()), songs(DiccionarioHash<Cancion, SongInfo>()) {}
	void addSong(const Cancion& c, const Artista& a, int d);
	void addToPlaylist(const Cancion& c);
	Cancion current();
	void play();
	void deleteSong(const Cancion& c);
	int totalTime(); 	
Cancion recent();
};
// creación de la información de la canción
// APDO. B: Los iteradores de momento no tienen que apuntar a nada porque lo único
// que estamos haciendo es meter la canción en la colección de canciones existentes
void iPud::addSong(const Cancion& c, const Artista& a, int d){
	if (songs.contiene(c)) throw ECancionExistente();
	SongInfo i(playlist.end(), played.end());
	i.artist = a; 
	i.duration = d; 
	// inclusión en el diccionario
	songs.inserta(c,i);
}
void iPud::addToPlaylist(const Cancion& c){
	if (!songs.contiene(c))throw ECancionNoExistente();
	Lista<Cancion>::Iterator it = playlist.end();
	if (songs.valorPara(c).itPlaylist == it){
		playlist.pon_ppio(c);
		Lista<Cancion>::Iterator ite = playlist.begin();
		songs.busca(c).valor().itPlaylist = ite;
		duration += songs.valorPara(c).duration;
	}
}
Cancion iPud::current(){
	if (playlist.esVacia()){
		cout << "LISTA DE REPRODUCCION VACIA" << endl;
	}
	else{
		return playlist.ultimo();
	}
}
void iPud::play(){
	if (!playlist.esVacia()){
		played.pon_ppio(playlist.ultimo()); //meto en played la cancion
		Lista<Cancion>::Iterator it = played.begin();
		songs.busca(played.ultimo()).valor().itPlayed = it;// meto el iterador de conde esta en played
		duration -= songs.valorPara(playlist.ultimo()).duration;//cambio la duracion
		playlist.eliminar(songs.valorPara(playlist.ultimo()).itPlaylist);//borro la cancion de playlist
	}
}
void iPud::deleteSong(const Cancion& c){
	if (songs.contiene(c)){
		Lista<Cancion>::Iterator it = playlist.end();
		Lista<Cancion>::Iterator ite = played.end();
		if (songs.valorPara(c).itPlaylist != it){
			playlist.eliminar(songs.valorPara(c).itPlaylist);
		}
		if (songs.valorPara(c).itPlayed != ite){
			played.eliminar(songs.valorPara(c).itPlayed);
		}
		songs.borra(c);
	}
}
int iPud::totalTime(){
	if (!playlist.esVacia()){
		return  duration;
	}
	else
		return 0;
}
Cancion iPud::recent(){
	if (played.esVacia()){
		cout << "LISTA DE REPRODUCCION VACIA" << endl;
	}
	else{
		return played.ultimo();
	}
	
}


/////MAIN
void añade(iPud& ip) {
	Cancion c;
	Artista a;
	int d;
	cin >> c >> a >> d;
	try {
		ip.addSong(c, a, d);
		cout << "OK" << endl;
	}
	catch (ECancionExistente) {
		cout << "CANCION_EXISTENTE" << endl;
	}
}

void añadelista(iPud& ip) {
	try {
		Cancion c;
		cin >> c;
		ip.addToPlaylist(c);
		cout << "OK" << endl;
	}
	catch (ECancionNoExistente) {
		cout << "CANCION_NO_EXISTENTE" << endl;
	}
}

void borra(iPud& ip) {
	Cancion c;
	cin >> c;
	ip.deleteSong(c);
	cout << "OK" << endl;
}
void playe(iPud& ip){
	ip.play();
}

void current(iPud& ip) {
		Cancion c;
		c =ip.current();
		cout << c << endl;
}
void tiemposs(iPud& ip){
	int tiempo;
	tiempo = ip.totalTime();
	cout << "tiempo total " << tiempo << endl;
}
void rec(iPud& ip){
	Cancion c;
	c = ip.recent();
	cout << c << endl;
}
int main() {
	iPud ip;
	string comando;
	while (cin >> comando) {
		if (comando == "anade") añade(ip);
		else if (comando == "lista") añadelista(ip);
		else if (comando == "play") playe(ip);
		else if (comando == "actu") current(ip);
		else if (comando == "borra") borra(ip);
		else if (comando == "tiempo") tiemposs(ip);
		else if (comando == "recent") rec(ip);
	}
	return 0;
}