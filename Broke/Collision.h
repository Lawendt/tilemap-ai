#pragma once
#include "Header.h"
#include "GameObject.h"
#ifndef PI
#define PI 3.14159265358979
#endif
/// Collision by Gabriel
/*
/*static bool lgCollision(float x1, float y1, SpriteSheet* spr1, float x2, float y2, SpriteSheet* spr2)
{
	float centX1 = (x1 + spr1->getWidth() / 2.0);
	float centY1 = (y1 + spr1->getHeight() / 2.0);
	float centX2 = (x2 + spr2->getWidth() / 2.0);
	float centY2 = (y2 + spr2->getHeight() / 2.0);

	if (abs(centX1 - centX2) < (spr1->getWidth() + spr2->getWidth()) / 2.0)
	{
		if (abs(centY1 - centY2) < (spr1->getHeight() + spr2->getHeight()) / 2.0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}*/
/*
//Collision by GabrielModified
static bool Collide(Law::GameObject &object1, Law::GameObject& object2) // Objects with anchor in the center
{
	float centX1 = (object1.getPosition().x );
	float centY1 = (object1.getPosition().y );
	float centX2 = (object2.getPosition().x );
	float centY2 = (object2.getPosition().y );

	if (abs(centX1 - centX2) < ((object1.getWidth() * object1.getScale().x) + (object2.getWidth() * object2.getScale().x)) / 2.0)
	{
		if (abs(centY1 - centY2) < ((object1.getHeight() * object1.getScale().y) + (object2.getHeight() * object1.getScale().y)) / 2.0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
*/


//uniColisaoLinhaComLinha
static bool CollideLineWithLine(float linhaA_x0, float linhaA_y0, float linhaA_x1, float linhaA_y1, float linhaB_x0, float linhaB_y0, float linhaB_x1, float linhaB_y1)
{
	float denominador = ((linhaB_y1 - linhaB_y0) * (linhaA_x1 - linhaA_x0)) - ((linhaB_x1 - linhaB_x0) * (linhaA_y1 - linhaA_y0));

	if (denominador == 0)
		return false;

	float ua = (((linhaB_x1 - linhaB_x0) * (linhaA_y0 - linhaB_y0)) - ((linhaB_y1 - linhaB_y0) * (linhaA_x0 - linhaB_x0))) / denominador;
	float ub = (((linhaA_x1 - linhaA_x0) * (linhaA_y0 - linhaB_y0)) - ((linhaA_y1 - linhaA_y0) * (linhaA_x0 - linhaB_x0))) / denominador;

	if ((ua < 0.0) || (ua > 1.0) || (ub < 0.0) || (ub > 1.0))
		return false;

	return true;
}

//uniColisaoLinhaComLinha recall
static bool CollideLineWithLine(sf::Vector2f A0, sf::Vector2f A1, sf::Vector2f B0, sf::Vector2f B1)
{
	return CollideLineWithLine(A0.x, A0.y, A1.x, A1.y, B0.x, B0.y, B1.x, B1.y);
}

//UniColisaoPontoComRetangulo
static bool CollidePointWithRect(float ponto_x, float ponto_y, float x, float y, float rot, float largura, float altura, float ancora_x, float ancora_y)
{
	//	invez de rotacionar o retangulo, transladar, e calcular se o ponto est� dentro dele
	//	vamos transladar o retangulo, rotacionar o ponto e calcular se o ponto est� dentro do retangulo
	//	essa abordagem � muito mais simples e r�pida, pois o retangulo fica alinhado aos eixos, facilitando o calculo

	//	primeiro translada o retangulo para a origem
	sf::Rect<int> rect;
	rect.width = (int)largura;
	rect.height = (int)altura;
	rect.left = (int)(-ancora_x*rect.width);
	rect.top = (int)(-ancora_y*rect.height);

	//	depois, translada o ponto para a origem e rotaciona ao contrario
	sf::Vector2f vec;
	vec.x = ponto_x - x;
	vec.y = ponto_y - y;

	float rad = (-rot)*(float)(PI / 180.0);	//	rota��o ao contrario
	float cs = cos(rad);
	float sn = sin(rad);

	ponto_x = vec.x * cs - vec.y * sn;
	ponto_y = vec.x * sn + vec.y * cs;

	//	por fim, calcula se o ponto est� dentro do retangulo
	return ((ponto_x <= rect.left + rect.width) && (ponto_x >= rect.left) && (ponto_y <= rect.top + rect.height) && (ponto_y >= rect.top));
}

//UniColisaoPontoComRetangulo recall
static bool CollidePointWithRect(sf::Vector2f point, sf::Vector2f rec, float rot, sf::Vector2f recDimension, Vector2f recAncor)
{
	return CollidePointWithRect(point.x, point.y, rec.x, rec.y, rot, recDimension.x, recDimension.y, recAncor.x, recAncor.y);
}

//UnicolisaoRetanguloComRetangulo modified 
static bool Collide(Law::GameObject &object1, Law::GameObject& object2, bool Inside = true)
{
	sf::Vector2f pOne = object1.getPosition(), dOne, aOne, pTwo, dTwo, aTwo;

	dOne.x = object1.getWidth() * object1.getScale().x;
	dOne.x = object1.getHeight() * object1.getScale().y;

	dTwo.x = object2.getWidth() * object2.getScale().x;
	dTwo.x = object2.getHeight() * object2.getScale().y;

	aOne.x = (object1.getOrigin().x / object1.getWidth());
	aOne.y = (object1.getOrigin().y / object1.getHeight());

	aTwo.x = (object2.getOrigin().x / object2.getWidth());
	aTwo.y = (object2.getOrigin().y / object2.getHeight());


	float rOne = object1.getRotation(), rTwo = object2.getRotation();
	//	1) calcula linhas do retangulo 1
	//	coloca a ancora do retangulo na origem
	sf::Vector2f canto_retan;
	canto_retan.x = -aOne.x *dOne.x;
	canto_retan.y = -aOne.y*dOne.y;

	sf::Vector2f pontos[4];
	pontos[0].x = canto_retan.x;			pontos[0].y = canto_retan.y;
	pontos[1].x = canto_retan.x + dOne.x;	pontos[1].y = canto_retan.y;
	pontos[2].x = canto_retan.x + dOne.x; pontos[2].y = canto_retan.y + dOne.y;
	pontos[3].x = canto_retan.x;			pontos[3].y = canto_retan.y + dOne.y;

	float rad = rOne*(float)(PI / 180.0);
	float cs = cos(rad);
	float sn = sin(rad);

	for (int i = 0; i < 4; ++i)
	{
		//	rotaciona os pontos (em rela��o a origem)
		float xx = pontos[i].x * cs - pontos[i].y * sn;
		float yy = pontos[i].x * sn + pontos[i].y * cs;

		//	translada os pontos de volta
		pontos[i].x = xx + pOne.x;
		pontos[i].y = yy + pOne.y;
	}

	//	calcula as 4 linhas do retangulo
	sf::Vector2f linhasA[4][2];	// 4 linhas, cada uma com 2 pontos
	linhasA[0][0] = pontos[0];
	linhasA[0][1] = pontos[1];
	linhasA[1][0] = pontos[1];
	linhasA[1][1] = pontos[2];
	linhasA[2][0] = pontos[2];
	linhasA[2][1] = pontos[3];
	linhasA[3][0] = pontos[3];
	linhasA[3][1] = pontos[0];

	//	2) calcula linhas do retangulo 2
	//	coloca a ancora do retangulo na origem
	canto_retan.x = -aTwo.x*dTwo.x;
	canto_retan.y = -aTwo.y*dTwo.y;

	pontos[0].x = canto_retan.x;			pontos[0].y = canto_retan.y;
	pontos[1].x = canto_retan.x + dTwo.x;	pontos[1].y = canto_retan.y;
	pontos[2].x = canto_retan.x + dTwo.x; pontos[2].y = canto_retan.y + dTwo.y;
	pontos[3].x = canto_retan.x;			pontos[3].y = canto_retan.y + dTwo.y;

	rad = rTwo*(float)(PI / 180.0);
	cs = cos(rad);
	sn = sin(rad);

	for (int i = 0; i < 4; ++i)
	{
		//	rotaciona os pontos (em rela��o a origem)
		float xx = pontos[i].x * cs - pontos[i].y * sn;
		float yy = pontos[i].x * sn + pontos[i].y * cs;

		//	translada os pontos de volta
		pontos[i].x = xx + pTwo.x;
		pontos[i].y = yy + pTwo.y;
	}

	//	calcula as 4 linhas do retangulo
	sf::Vector2f linhasB[4][2];	// 4 linhas, cada uma com 2 pontos
	linhasB[0][0] = pontos[0];
	linhasB[0][1] = pontos[1];
	linhasB[1][0] = pontos[1];
	linhasB[1][1] = pontos[2];
	linhasB[2][0] = pontos[2];
	linhasB[2][1] = pontos[3];
	linhasB[3][0] = pontos[3];
	linhasB[3][1] = pontos[0];

	//	testa intersec��o entre as linhas de um retangulo contra as linhas do outro
	bool colidiu = false;
	for (int i = 0; i < 4 && !colidiu; ++i)
	{
		for (int j = 0; j < 4 && !colidiu; ++j)
		{
			colidiu = CollideLineWithLine(linhasA[i][0].x, linhasA[i][0].y, linhasA[i][1].x, linhasA[i][1].y,
				linhasB[j][0].x, linhasB[j][0].y, linhasB[j][1].x, linhasB[j][1].y);
		}
	}

	//	se n�o ouve nenhuma intersec��o
	//	pode ser que um retangulo esteja totalmente dentro do outro,
	//	ent�o testa este caso

	if (!colidiu && Inside)
	{
		colidiu = CollidePointWithRect(object1.getPosition(), object2.getPosition(), object2.getRotation(), object2.getDimensions(), aTwo)
			|| CollidePointWithRect(object2.getPosition(), object1.getPosition(), object1.getRotation(), object1.getDimensions(),aOne);
	}

	return colidiu;
}



//ex try
//static bool Collide(Law::GameObject g, Law::GameObject h)
//{
//	sf::Rect<float> one, two;
//
//	one.left = g.getPosition().x - g.getOrigin().x * g.getScale().x;
//	one.width = g.getWidth()* g.getScale().x;
//	one.top = g.getPosition().y - g.getOrigin().y* g.getScale().y;
//	one.height = g.getHeight()* g.getScale().y;
//
//	
//	two.left = h.getPosition().x - h.getOrigin().x* h.getScale().x;
//	two.width = h.getWidth()* h.getScale().x;
//	two.top = h.getPosition().y - h.getOrigin().y* h.getScale().y;
//	two.height = h.getHeight()* h.getScale().y;
//
//	
//
//	return one.intersects(two);
//
//}
//
//static bool Collide(Law::GameObject g, sf::Rect<float> two)
//{
//	sf::Rect<float> one;
//
//	sf::VertexArray vertex = *(g.getVertices());
//	one.left = vertex[0].position.x;
//	one.width = vertex[1].position.x - vertex[0].position.x;
//	one.top = vertex[0].position.y;
//	one.height = vertex[2].position.y - vertex[0].position.y;
//
//	one.left = vertex[0].position.x;
//	one.width = vertex[1].position.x - vertex[0].position.x;
//	one.top = vertex[0].position.y;
//	one.height = vertex[2].position.y - vertex[0].position.y;
//
//	return one.intersects(two);
//
//}
//
//static bool CollisionHorizontal(Law::GameObject target, Law::GameObject particle) // It's not an precise Collision
//{
//	sf::Rect<float> targetleft, targetRight, particleall;
//
//	particleall.left = particle.getPosition().x - particle.getOrigin().x * particle.getScale().x;
//	particleall.width = particle.getWidth()* particle.getScale().x;
//	particleall.top = particle.getPosition().y - particle.getOrigin().y* particle.getScale().y;
//	particleall.height = particle.getHeight()* particle.getScale().y;
//
//
//	targetRight.left = target.getPosition().x + target.getOrigin().x* target.getScale().x - 25;
//	targetRight.width = 25;
//	targetRight.top = target.getPosition().y + target.getOrigin().y* target.getScale().y  ;
//	targetRight.height = target.getHeight()* target.getScale().y;
//
//	targetleft.left = target.getPosition().x - target.getOrigin().x* target.getScale().x ;
//	targetleft.width = 25;
//	targetleft.top = target.getPosition().y - target.getOrigin().y* target.getScale().y;
//	targetleft.height = target.getHeight()* target.getScale().y ;
//
//
//
//	return (particleall.intersects(targetleft) || particleall.intersects(targetRight));
//}