import re
from collections import defaultdict
import sys


class Team:
	def __init__(self, goals=0, matches=0, opens=0):
		self.goals = goals
		self.matches = matches
		self.opens = opens


class Player:
	def __init__(self, team=None, goals=0, opens=0):
		self.goals_dict = defaultdict(int)
		self.team = team
		self.goals = goals
		self.opens = opens


"""
Total goals for <Название команды>
Mean goals per game for <Название команды>
Total goals by <Имя игрока>
Mean goals per game by <Имя игрока>
Goals on minute <Минута> by <Имя игрока>
Goals on first <T> minutes by <Имя игрока>
Goals on last <T> minutes by <Имя игрока>
Score opens by <Название команды>
Score opens by <Имя игрока>
"""

teams = defaultdict(Team)
players = defaultdict(Player)

with open('input.txt', 'r') as fin:
	with open('output.txt', 'w') as fout:
		sys.stdout = fout

		while True:
			line = fin.readline().strip(' \n')

			if not line:
				break

			if '-' in line:
				result = re.split(r"(\s\-\s|\:)", line)
				team1, team2 = re.search(r"[\"\w\s\-]+(?=\s\d)", line).group(0).split(' - ');
				goals1, goals2 = map(int, re.search(r"\d+:\d+", line).group(0).split(':'))

				# ['"Juventus"', ' - ', '"Milan"', ' ', '3', ':', '1', '\n', '']
				teams[team1].goals += goals1
				teams[team2].goals += goals2
				teams[team1].matches += 1
				teams[team2].matches += 1

				open_min = 91
				open_name, open_team = None, None

				for i in range(goals1):
					line = fin.readline()
					name, minute = line.strip(" '\n").rsplit(None, 1)
					minute = int(minute)

					players[name].goals_dict[minute] += 1
					players[name].goals += 1

					if players[name].team is None:
						players[name].team = team1

					if open_min > minute:
						open_name = name 
						open_team = team1
						open_min = minute

				for i in range(goals2):
					line = fin.readline()
					name, minute = line.strip(" '\n").rsplit(None, 1)
					minute = int(minute)

					players[name].goals_dict[minute] += 1
					players[name].goals += 1

					if players[name].team is None:
						players[name].team = team2

					if open_min > minute:
						open_name = name 
						open_team = team2
						open_min = minute

				if open_name is not None:
					players[open_name].opens += 1
					teams[open_team].opens += 1

			else:
				command, _, name = re.split(r"(\sby\s|\sfor\s)", line)
				# print(command, name)

				if command == 'Total goals':
					if name in teams.keys():
						print(teams[name].goals)
					else:
						print(players[name].goals)

				elif command == 'Mean goals per game':
					if name in teams.keys():
						team = teams[name]
						print(team.goals / team.matches)
					else:
						player = players[name]
						print(player.goals / teams[player.team].matches)

				elif command.startswith('Goals'):
					minute = int(re.search(r'\b\d{1,2}\b', command).group(0))
					if command.startswith('Goals on minute'):
						print(players[name].goals_dict[minute])
					elif command.startswith('Goals on first'):
						res = 0
						for key, val in players[name].goals_dict.items():
							if key <= minute:
								res += val
						print(res)

					else:
						res = 0
						minute = 91 - minute
						for key, val in players[name].goals_dict.items():
							if key >= minute:
								res += val
						print(res)

				elif (command == 'Score opens'):
					if name in teams.keys():
						print(teams[name].opens)
					else:
						print(players[name].opens)