#include "Doom.hpp"

void DoomAdventure::update()
{
	if (level1 == true)
	{
		mYSt2.loadFromFile("assets/Background/bg1.png");
		r2.setTexture(mYSt2, true);
		r2.setColor(sf::Color::White);
		r2.setScale(1, 1);
	}
	if (level2 == true)
	{
		mYSt2.loadFromFile("assets/Background/bg2.png");
		r2.setTexture(mYSt2, true);
		r2.setColor(sf::Color::White);
		r2.setScale(1, 1);
	}
	if (level3 == true)
	{
		mYSt2.loadFromFile("assets/Background/bg3.png");
		r2.setTexture(mYSt2, true);
		r2.setColor(sf::Color::White);
		r2.setScale(1, 1);
	}

	mYSt3.loadFromFile("assets/Menu/02.png");
	r3.setTexture(mYSt3, true);
	r3.setColor(sf::Color::Red);
	r3.setScale(2, 2);
	static sf::Vector2i position(1, 17);
	static sf::Vector2i size(33, 30);
	r3.setTextureRect(sf::IntRect(position, size));

	logotexture.loadFromFile("assets/Hero/Gunner/Gunner_Crouch.png");
	n1.setTexture(logotexture);
	n1.setTextureRect(sf::IntRect(13, 29, 26, 24));
	n1.setScale(2, 2);
	n1.setColor(sf::Color::White);
	view->setSize(window->getSize().x / 2, window->getSize().y / 2);

	if (view->getCenter().x == window->getSize().x / 2)
	{
		if (view->getCenter().y == window->getSize().y / 2)
		{
			view->setCenter(320, heroobj->hero->getPosition().y);
		}
	}

	if (level == 1)
	{
		if (heroobj->hero->getPosition().x > 320 and heroobj->hero->getPosition().x < 2240)
		{
			view->setCenter(heroobj->hero->getPosition());
			r1.setPosition(heroobj->hero->getPosition().x - 320, heroobj->hero->getPosition().y - 200);
			r2.setPosition(heroobj->hero->getPosition().x - 360, heroobj->hero->getPosition().y - 400);
			r3.setPosition(heroobj->hero->getPosition().x - 310, heroobj->hero->getPosition().y - 130);
			bulletmenuSprite.setPosition(r3.getPosition().x + 70, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().y < 180 and heroobj->hero->getPosition().x < 2240)
		{
			r2.setPosition(0, -300);
			r3.setPosition(0, -300);
		}
		else if (heroobj->hero->getPosition().x > 2000)
		{
			view->setCenter(view->getCenter().x, heroobj->hero->getPosition().y);
			r1.setPosition(2316, heroobj->hero->getPosition().y - 200);
			r3.setPosition(2441, heroobj->hero->getPosition().y - 130);
			r2.setPosition(1856, heroobj->hero->getPosition().y - 400);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().x > 2240)
		{
			r2.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			r3.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}
		else
		{
			view->setCenter(view->getCenter().x, heroobj->hero->getPosition().y);
			r1.setPosition(420, heroobj->hero->getPosition().y - 200);
			r3.setPosition(555, heroobj->hero->getPosition().y - 130);
			r2.setPosition(0, 0);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}

		n1.setPosition(r3.getPosition().x - 5, r3.getPosition().y);

		if (heroobj->hero->getPosition().x < 0)
		{
			heroobj->hero->setPosition(0, heroobj->hero->getPosition().y);
		}
		if (heroobj->hero->getPosition().x > 2472)
		{
			heroobj->hero->setPosition(2472, heroobj->hero->getPosition().y);
		}
	}

	else if (level == 2)
	{
		if (heroobj->hero->getPosition().x > 320 and heroobj->hero->getPosition().x < 2240)
		{
			view->setCenter(heroobj->hero->getPosition());
			r1.setPosition(heroobj->hero->getPosition().x - 320, heroobj->hero->getPosition().y - 200);
			r2.setPosition(heroobj->hero->getPosition().x - 360, heroobj->hero->getPosition().y - 400);
			r3.setPosition(heroobj->hero->getPosition().x - 310, heroobj->hero->getPosition().y - 130);
			bulletmenuSprite.setPosition(r3.getPosition().x + 70, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().y < 180 and heroobj->hero->getPosition().x < 2240)
		{
			r2.setPosition(0, -300);
			r3.setPosition(0, -300);
		}
		else if (heroobj->hero->getPosition().x > 2000)
		{
			view->setCenter(2236, heroobj->hero->getPosition().y);
			r1.setPosition(2316, heroobj->hero->getPosition().y - 200);
			r3.setPosition(2441, heroobj->hero->getPosition().y - 130);
			r2.setPosition(1856, heroobj->hero->getPosition().y - 400);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().x > 2240)
		{
			r2.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			r3.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}
		else
		{
			view->setCenter(view->getCenter().x, heroobj->hero->getPosition().y);
			r1.setPosition(420, heroobj->hero->getPosition().y - 200);
			r3.setPosition(555, heroobj->hero->getPosition().y - 130);
			r2.setPosition(0, 0);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}

		n1.setPosition(r3.getPosition().x - 5, r3.getPosition().y);

		if (heroobj->hero->getPosition().x < 0)
		{
			heroobj->hero->setPosition(0, heroobj->hero->getPosition().y);
		}
		if (heroobj->hero->getPosition().x > 2472)
		{
			heroobj->hero->setPosition(2472, heroobj->hero->getPosition().y);
		}
	}
	else if (level == 3)
	{
		if (heroobj->hero->getPosition().x > 320 and heroobj->hero->getPosition().x < 2240)
		{
			view->setCenter(heroobj->hero->getPosition());
			r1.setPosition(heroobj->hero->getPosition().x - 320, heroobj->hero->getPosition().y - 200);
			r2.setPosition(heroobj->hero->getPosition().x - 360, heroobj->hero->getPosition().y - 400);
			r3.setPosition(heroobj->hero->getPosition().x - 310, heroobj->hero->getPosition().y - 130);
			bulletmenuSprite.setPosition(r3.getPosition().x + 70, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().y < 180 and heroobj->hero->getPosition().x < 2240)
		{
			r2.setPosition(0, -300);
			r3.setPosition(0, -300);
		}
		else if (heroobj->hero->getPosition().x > 2000)
		{
			view->setCenter(2236, heroobj->hero->getPosition().y);
			r1.setPosition(2316, heroobj->hero->getPosition().y - 200);
			r3.setPosition(2441, heroobj->hero->getPosition().y - 130);
			r2.setPosition(1856, heroobj->hero->getPosition().y - 400);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().x > 2240)
		{
			r2.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			r3.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
		}
		else if (heroobj->hero->getPosition().x >= 0 and heroobj->hero->getPosition().x <= 320)
		{

			view->setCenter(320, heroobj->hero->getPosition().y);
			view->setCenter(view->getCenter().x, heroobj->hero->getPosition().y);
			r1.setPosition(420, heroobj->hero->getPosition().y - 200);
			r3.setPosition(555, heroobj->hero->getPosition().y - 130);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
			r2.setPosition(0, 0);
		}
		else
		{
			view->setCenter(view->getCenter().x, heroobj->hero->getPosition().y);
			r1.setPosition(420, heroobj->hero->getPosition().y - 200);
			r3.setPosition(555, heroobj->hero->getPosition().y - 130);
			bulletmenuSprite.setPosition(r3.getPosition().x - 90, r3.getPosition().y + 10);
			r2.setPosition(0, 0);
		}

		n1.setPosition(r3.getPosition().x - 5, r3.getPosition().y);

		if (heroobj->hero->getPosition().x < 0)
		{
			heroobj->hero->setPosition(0, heroobj->hero->getPosition().y);
		}
		if (heroobj->hero->getPosition().x > 2472)
		{
			heroobj->hero->setPosition(2472, heroobj->hero->getPosition().y);
		}
	}

	if (heroobj->hero->getPosition().y > 0)
	{
		if (layerDown->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
							   (int)(heroobj->hero->getPosition().y + heroobj->hero->getGlobalBounds().height) / 32)
				.ID)
		{
			// Colidiu / Aplica gravidade
		}
		if (level1 == true)
		{
			heroobj->DownCountColison = layerDown->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
														   (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											.ID;

			heroobj->LeftCountColison = layerLeft->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
														   (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											.ID;

			heroobj->RightCountColison = layerRight->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											 .ID;

			heroobj->UpCountColison = layerUp->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
													   (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
										  .ID;
		}

		if (level2 == true)
		{
			heroobj->DownCountColison = layerDown_2->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											.ID;

			heroobj->LeftCountColison = layerLeft_2->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											.ID;

			heroobj->RightCountColison = layerRight_2->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															   (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											 .ID;

			heroobj->UpCountColison = layerUp_2->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
														 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
										  .ID;

			heroobj->SpikesColision = layerSpikes->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
														   (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
										  .ID;
		}
		if (level3 == true)
		{
			heroobj->DownCountColison = layerDown_3->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											.ID;

			heroobj->LeftCountColison = layerLeft_3->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											.ID;

			heroobj->RightCountColison = layerRight_3->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
															   (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
											 .ID;

			heroobj->UpCountColison = layerUp_3->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
														 (int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height / 2) + 30) / 32)
										  .ID;
		}

		npcA1->DownCountColison = layerDown->getTile((int)(npcA1->npc->getPosition().x + npcA1->npc->getGlobalBounds().width / 2) / 32,
													 (int)(npcA1->npc->getPosition().y + (npcA1->npc->getGlobalBounds().height / 2)) / 32)
									  .ID;
		npcA1->LeftCountColison = layerLeft->getTile((int)(npcA1->npc->getPosition().x + npcA1->npc->getGlobalBounds().width / 2) / 32,
													 (int)(npcA1->npc->getPosition().y + (npcA1->npc->getGlobalBounds().height / 2)) / 32)
									  .ID;
		npcA1->RightCountColison = layerRight->getTile((int)(npcA1->npc->getPosition().x + npcA1->npc->getGlobalBounds().width / 2) / 32,
													   (int)(npcA1->npc->getPosition().y + (npcA1->npc->getGlobalBounds().height / 2)) / 32)
									   .ID;
		npcA1->UpCountColison = layerUp->getTile((int)(npcA1->npc->getPosition().x + npcA1->npc->getGlobalBounds().width / 2) / 32,
												 (int)(npcA1->npc->getPosition().y + (npcA1->npc->getGlobalBounds().height / 2)) / 32)
									.ID;

		npcA2->DownCountColison = layerDown->getTile((int)(npcA2->npc->getPosition().x + npcA2->npc->getGlobalBounds().width / 2) / 32,
													 (int)(npcA2->npc->getPosition().y + (npcA2->npc->getGlobalBounds().height / 2)) / 32)
									  .ID;
		npcA2->LeftCountColison = layerLeft->getTile((int)(npcA2->npc->getPosition().x + npcA2->npc->getGlobalBounds().width / 2) / 32,
													 (int)(npcA2->npc->getPosition().y + (npcA2->npc->getGlobalBounds().height / 2)) / 32)
									  .ID;
		npcA2->RightCountColison = layerRight->getTile((int)(npcA2->npc->getPosition().x + npcA2->npc->getGlobalBounds().width / 2) / 32,
													   (int)(npcA2->npc->getPosition().y + (npcA2->npc->getGlobalBounds().height / 2)) / 32)
									   .ID;
		npcA2->UpCountColison = layerUp->getTile((int)(npcA2->npc->getPosition().x + npcA2->npc->getGlobalBounds().width / 2) / 32,
												 (int)(npcA2->npc->getPosition().y + (npcA2->npc->getGlobalBounds().height / 2)) / 32)
									.ID;
	}
	window->setView(*view);

	if (heroobj->hero->getGlobalBounds().intersects(checkpoint.getGlobalBounds()) and skiplevel == false)
	{
		checkpoint.setPosition(1000, 1000);
		skiplevel = true;
	}

	if (skiplevel == true and level <= 2)
	{
		static float g = 0;
		g += 3;
		transition.setColor(sf::Color(0, 0, 0, g));

		if (g >= 255)
		{
			transition.setColor(sf::Color::Transparent);
			g = 0;
			skiplevel = false;
			level++;
			if (level == 2)
			{
				checkpoint.setSize(sf::Vector2f(60, 100));
				checkpoint.setPosition(2472, 178);
			}
			if (level == 3)
			{
				view->setSize(window->getSize().x / 2, window->getSize().y / 2);
			}
			Restart();
		}
	}

	if (level == 1)
	{
		level1 = true;
		level2 = false;
		level3 = false;
	}

	if (level == 2)
	{
		level2 = true;
		level1 = false;
		level3 = false;
		view->setCenter(320, heroobj->hero->getPosition().y);
	}

	if (level == 3)
	{

		level3 = true;
		level2 = false;
		level1 = false;
	}


}
